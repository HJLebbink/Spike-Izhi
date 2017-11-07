// The MIT License (MIT)
//
// Copyright (c) 2017 Henk-Jan Lebbink
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <memory>	// for std::shared_ptr

#include <stdio.h>		// for printf
#include <chrono>
#include <future>
#include <functional> // for std::ref

#include "../../Spike-Tools-LIB/SpikeRuntimeOptions.hpp"
#include "../../Spike-Tools-LIB/SpikeSet1Sec.hpp"
#include "../../Spike-Tools-LIB/DumperSpikes.hpp"
#include "../../Spike-Tools-LIB/DumperTopology.hpp"
#include "../../Spike-Tools-LIB/SpikeTypes.hpp"
#include "../../Spike-Tools-LIB/SpikeNetworkPerformance.hpp"
#include "../../Spike-Tools-LIB/assert.ipp"

#include "../../Spike-DataSet-LIB/SpikeStream.hpp"

#include "../../Spike-Izhikevich-LIB/DumperState.hpp"
#include "../../Spike-Izhikevich-LIB/Topology.hpp"

#include "../../Spike-Izhikevich-LIB/v1/PolyChronousGroup.hpp"
#include "../../Spike-Izhikevich-LIB/v1/PolyChronousGroups.hpp"
#include "../../Spike-Izhikevich-LIB/v1/updateState_serial.hpp"

namespace spike
{
	namespace v1
	{
		using namespace spike;
		using namespace spike::tools;
		using namespace spike::dataset;

		template <typename Topology_i>
		class SpikeNetwork1
		{
		public:
			static const bool PROFILE = false;

			using TimePoint = std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration>;

			////////////////////////////////////////////////////////////////////////
			// public static constants
			////////////////////////////////////////////////////////////////////////
			using Topology = Topology_i;
			using SpikeNetwork = SpikeNetwork1<Topology>;

			static const size_t Ne = Topology::Ne;
			static const size_t Ni = Topology::Ni;
			static const size_t Nm = Topology::Nm;
			static const size_t Ns = Topology::Ns;

			static const size_t M = Topology::M;
			static const Delay D = Topology::D;

			static const size_t nNeurons = Topology::nNeurons;
			static const size_t N = Topology::N;

			////////////////////////////////////////////////////////////////////////
			// public member fields
			////////////////////////////////////////////////////////////////////////
			Synapse synapse_[nNeurons][D][M];			// arrangement of delays, this array contains synapses
			SynapseLength synapse_size_[nNeurons][D];	// number of synapses in synapse_; 

			Pre		pre_[nNeurons][spike::v1::constant::maxPreCounter];
			unsigned short pre_size_[nNeurons];			// number of incomming pathways of a neuron, maximum is maxPreCounter

			NeuronId post_[nNeurons][M];				// indeces of postsynaptic neurons; post_[neuronId][synapse] = neuronId
			unsigned short post_size_[nNeurons];		// number of outgoing pathways of a neuron (M is the max)

			Weight2 s_[N][M];							// matrix of synaptic weights
			Weight2 sd_[N][M];							// matrix of weights derivatives
			Weight2 *s_pre_[nNeurons][spike::v1::constant::maxPreCounter];	// presynaptic weights
			Weight2 *sd_pre_[nNeurons][spike::v1::constant::maxPreCounter];	// presynaptic weights

			float __declspec(align(4)) ltp_[N][1001 + D];		// STDP functions: long term potentiation
			float __declspec(align(4)) ltd_[N];				// STDP functions: long term depression

			float __declspec(align(4)) a_[N];					// neuronal dynamics parameters
			float __declspec(align(4)) b_[N];					// neuronal dynamics parameters
			float __declspec(align(4)) c_[N];					// neuronal dynamics parameters
			float __declspec(align(4)) d_[N];					// neuronal dynamics parameters
			float __declspec(align(4)) v_[N];					// activity variables
			float __declspec(align(4)) u_[N];					// activity variables

			float __declspec(align(4)) trainRate_[N];
			float __declspec(align(4)) inputCurrent_[N];
			float __declspec(align(4)) inputScaling_[N];		// scaling of the inputCurrent

			SpikeSet1Sec<Ms> spikeData_;
			SpikeNetworkPerformance<Topology, Ms> spikeNetworkPerformance_;
			std::shared_ptr<SpikeStream<Topology>> spikeStream_;


			////////////////////////////////////////////////////////////////////////
			// following four datastructures are only used by parallel implementation
			////////////////////////////////////////////////////////////////////////
			std::vector<std::future<void>> results_;
			std::vector<NeuronId> firedNeurons_;
			//std::mutex mutex_;
			//Tools2Ns::ThreadPool threadPool_;

			////////////////////////////////////////////////////////////////////////
			// methods
			////////////////////////////////////////////////////////////////////////

			// destructor
			~SpikeNetwork1(void) = default;

			// constructor
			SpikeNetwork1(void) = delete;

			// constructor
			SpikeNetwork1(
				const SpikeRuntimeOptions& spikeRuntimeOptions)
				//: threadPool_(THREAD_POOL_SIZE)
				: spikeRuntimeOptions_(spikeRuntimeOptions)
				, dumperSpikes_(DumperSpikes<Ms>(spikeRuntimeOptions))
				, dumperTopology_(DumperTopology<Topology>(spikeRuntimeOptions))
				, dumperState_(DumperState<nNeurons>(spikeRuntimeOptions))
			{
				this->spikeData_.nFirings_ = 1;
			}

			// copy constructor
			SpikeNetwork1(const SpikeNetwork& other) = delete;

			void train(const unsigned int nSeconds, const bool useConfusionMatrix, const bool plotProgress)
			{
				std::cout << "SpikeNetwork1::train(): going to train for " << nSeconds << " seconds." << std::endl;

				this->initVoltageVariables();
				this->spikeStream_->start();

				this->startTime_ = std::chrono::system_clock::now();

				for (unsigned int sec = 0; sec < nSeconds; ++sec)
				{
					for (Ms t = 0; t < 1000; ++t)
					{			// simulation of 1 sec

						if (this->dumperState_.dumpTest(sec))
						{
							this->dumperState_.store_State(t, this->v_, this->u_, this->inputCurrent_);
						}

						//1] start a new case if needed
						this->spikeStream_->startNewCaseIfNeeded();
						//2] handle firing neurons 
						this->handleFiringNeurons<true>(t);
						//this->handleFiringNeurons_train_par(t); // train_par is much slower, not sure why.
						//3 update weight differential based on historic spikes
						this->updateInputCurrent<true>(t);
						//4] calculate the new potential
						this->updateState();
						//5] calculate the new STDP values
						this->updateStdp(t);
						//6] increment time in the stream
						this->spikeStream_->incTime();
					} // end of 1 second loop

					if (plotProgress)
					{
						this->plotProgressInfo(this->startTime_, sec, nSeconds);
					}

					if (useConfusionMatrix)
					{
						this->spikeNetworkPerformance_.addPerformanceMnist28x28(
							this->spikeStream_->getCaseUsage(),
							this->spikeData_,
							true);

						if (((sec % (10 * 60)) == 0) && (sec > 0))
						{
							std::cout << this->spikeNetworkPerformance_.toStringConfusionMatrix() << std::endl;
							//std::cout << this->spikeNetworkPerformance_.toStringPerformance() << std::endl;
							std::cout << "avg precision " << this->spikeNetworkPerformance_.getAveragePrecision() << std::endl;

							this->spikeNetworkPerformance_.clear();
						}
					}

					this->cleanupLtpData();

					if (this->dumperTopology_.dumpTest(sec))
					{
						this->dumperTopology_.dump(sec, "train", this->getTopology());
					}
					if (this->dumperSpikes_.dumpTest(sec))
					{
						this->dumperSpikes_.dump(sec, "train", this->spikeData_, this->spikeStream_->getCaseUsage());
					}
					if (this->dumperState_.dumpTest(sec))
					{
						this->dumperState_.dump(sec, "train");
					}

					this->cleanupFiringData();
					this->updateWeights();
				}
			}

			void sample(const unsigned int seconds)
			{
				std::cout << "Spike_Network_State::sample(): going to sample for " << seconds << " seconds." << std::endl;

				this->initVoltageVariables();

				Profiler::reset();

				this->startTime_ = std::chrono::system_clock::now();
				for (unsigned int sec = 0; sec < seconds; ++sec)
				{
					for (Ms t = 0; t < 1000; ++t)
					{			// simulation of 1 sec

						if (this->spikeNetworkDumpState_.dumpToFile_State(sec))
						{
							this->spikeNetworkDumpState_.store_State(t, this->v, this->u, this->inputCurrent_);
						}

						//1] start a new case if needed
						this->spikeStream_->startNewCaseIfNeeded();
						//2] handle firing neurons 
						this->handleFiringNeurons_sample(t);
						//3 update weight differential based on historic spikes
						this->updateInputCurrent_sample(t);
						//4] calculate the new potential
						this->updateState();
						//5] calculate the new STDP values
						this->spikeStream_->incTime();
					} // end of 1 second loop

					if (false)
					{
						this->spikeNetworkPerformance_.addPerformanceMnist14x14(
							this->spikeStream_->getCaseUsage(),
							this->spikeData_,
							true);

						if ((sec % (1 * 60)) == 0)
						{
							std::cout << this->spikeNetworkPerformance_.toString() << std::endl;
						}
					}

					this->plotProgressInfo(this->startTime_, sec, seconds);

					if (this->spikeNetworkDump_.dumpToFile_Spikes(sec))
					{
						this->spikeNetworkDump_.dumpToFile_Spikes(sec, "sample", this->spikeData_, this->spikeStream_);
					}
					if (this->spikeNetworkDumpState_.dumpToFile_State(sec))
					{
						this->spikeNetworkDumpState_.dumpToFile_State(sec, "sample");
					}

					this->cleanupFiringData();

					if (sec % 60 == 0)
					{
						Profiler::printElapsedTime();
						//std::cout << "NetworkLifV1::train(): A = firingReason; B = handleFiringNeuron; C = updateInputCurrent; D = updateState; E = updateWeights" << std::endl;
					}
				}
			}

			void sampleOneCase(
				const std::shared_ptr<const SpikeCaseFast>& spikeCaseRandom,
				const std::shared_ptr<const SpikeCaseFast>& spikeCaseData,
				SpikeSet1Sec<Ms>& spikeDataLocal,
				SpikeSet1Sec<Ms>& spikeDataDebug)
			{
				const Ms startUpTimeInMs = this->spikeRuntimeOptions_.getStartUpTimeInMs();
				const Ms sampleTimeInMs = this->spikeRuntimeOptions_.getSampleTimeInMs();
				std::cout << "Spike_Network_State::sampleOneCase: startUpTimeInMs=" << startUpTimeInMs << "; sampleTimeInMs=" << sampleTimeInMs << std::endl;

				//	std::cout << "NetworkLifV1::sampleOneCase(): startUpTimeInMs=" << startUpTimeInMs << "; sampleTimeInMs=" << sampleTimeInMs << " ms." << std::endl;
				if ((startUpTimeInMs + sampleTimeInMs) > 1000)
				{
					std::cerr << "Spike_Network_State::sampleOneCase(); startUpTimeInMs=" << startUpTimeInMs << "; sampleTimeInMs=" << sampleTimeInMs << ": incorrect parameters " << std::endl;
					throw std::exception();
				}

				// clear this network and the recorded spike data;
				this->initVoltageVariables();
				this->spikeData_.nFirings_ = 1;
				spikeDataLocal.clear();

				auto spikeStreamRandom = std::make_shared<SpikeStream<Topology>>(this->spikeRuntimeOptions_);
				spikeStreamRandom->add(spikeCaseRandom);
				this->setSpikeStream(spikeStreamRandom);
				spikeStreamRandom->start();

				//1] startup: run the network with random data 
				for (Ms time = 0; time < startUpTimeInMs; ++time)
				{
					//1] handle firing neurons 
					this->handleFiringNeurons<false>(time);
					//2] load input currents
					spikeStreamRandom->incTime();
					//3 update input current based on historic spikes
					this->updateInputCurrent<false>(time);
					//4] calculate the new potential
					this->updateState();
				} // end of startUpTimeInMs loop

				//2] provide case data: run the network with the case data; and record the spikes
				const Ms caseDurationPlusSilenceInMs = spikeCaseData->getDurationPlusSilenceInMs();

				auto spikeStreamData = std::make_shared<SpikeStream<Topology>>(this->spikeRuntimeOptions_);
				spikeStreamData->add(spikeCaseData);
				this->setSpikeStream(spikeStreamData);
				spikeStreamData->start();

				for (Ms timeCase = 0; timeCase < caseDurationPlusSilenceInMs; ++timeCase)
				{
					const Ms time = timeCase + startUpTimeInMs;
					//1] handle firing neurons 
					this->handleFiringNeurons_recordSpikes<false>(time, timeCase, spikeDataLocal);
					//2] load input currents
					spikeStreamData->incTime();
					//3 update input current based on historic spikes
					this->updateInputCurrent<false>(time);
					//4] calculate the new potential
					this->updateState();
				} // end of sampleTimeInMs loop

				//3] run the network with random data and record the spikes
				this->setSpikeStream(spikeStreamRandom);
				this->spikeStream_->start();

				for (Ms timeAfterCase = caseDurationPlusSilenceInMs; timeAfterCase < sampleTimeInMs; ++timeAfterCase)
				{
					const Ms time = timeAfterCase + startUpTimeInMs;
					//1] handle firing neurons 
					this->handleFiringNeurons_recordSpikes<false>(time, timeAfterCase, spikeDataLocal);
					//2] load input currents
					this->spikeStream_->incTime();
					//3 update input current based on historic spikes
					this->updateInputCurrent<false>(time);
					//4] calculate the new potential
					this->updateState();
				} // end of sampleTimeInMs loop

				spikeDataLocal.addCaseOccurance(CaseOccurance<Ms>(spikeCaseData->getCaseId(), 0, caseDurationPlusSilenceInMs, spikeCaseData->getCaseLabel()));
				spikeDataLocal.freeze();

				#ifdef _DEBUG
				//copy the local spikeData to the spikeDataDebug class
				spikeDataDebug.clear();

				spikeDataDebug.addCaseOccurance(CaseOccurance<Ms>(spikeCaseData->getCaseId(), startUpTimeInMs, startUpTimeInMs + caseDurationPlusSilenceInMs, spikeCaseData->getCaseLabel()));
				spikeDataDebug.setTimeSecond(0);
				for (unsigned int i = 1; i < this->spikeData_.nFirings_; ++i)
				{ // first element in firings is a dummy element
					if ((this->spikeData_.firingTime_[i] < 1000) && (this->spikeData_.firingTime_[i] >= 0))
					{
						spikeDataDebug.addFiring(this->spikeData_.firingTime_[i], this->spikeData_.firingNeuronId_[i], this->spikeData_.firingReason_[i]);
					}
				}
				spikeDataDebug.freeze();
				#endif
			}

			void setTopology(const std::shared_ptr<Topology>& topology)
			{
				this->topology_ = topology;

				// set all post post neuronId to NO_NEURON_ID, such that we can check afterwards that a synapse has not been initialized.
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					for (Synapse syn = 0; syn < M; ++syn)
					{
						this->post_[neuronId][syn] = NO_NEURON_ID;
					}
					for (Delay delay = 0; delay < D; ++delay)
					{
						this->synapse_size_[neuronId][delay] = 0;
					}
				}
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					Synapse syn = 0;
					for (unsigned int i = 0; i < topology->getNumberOfPathways(); ++i)
					{
						const Pathway p = topology->getPathway(i);
						if (p.origin == neuronId)
						{
							// check if this pathway already existed.
							bool exists = false;
							for (Synapse j = 0; j < syn; ++j)
							{
								if (this->post_[neuronId][j] == p.destination)
								{
									std::cerr << "NetworkLifV1::init(): Warning: pathway " << i << " already exist" << std::endl;
									exists = true;
								}
							}
							if (!exists)
							{
								if (syn >= M)
								{
									std::cerr << "NetworkLifV1::init(): Error in pathway " << i << ". Too many synapses for neuron " << p.origin << "; syn = " << syn << std::endl; throw 1;
								}
								const Delay delay = p.delay;
								this->post_[neuronId][syn] = p.destination;


								this->synapse_[neuronId][delay][this->synapse_size_[neuronId][delay]] = syn;
								this->synapse_size_[neuronId][delay]++;

								this->s_[neuronId][syn] = p.weight;
								this->sd_[neuronId][syn] = 0;

								syn++;
							}
						}
					}
					if (syn != M)
					{
						//std::cout << "Spike_Network_State::setTopology: neuron " << neuronId << " does not utilize all possible synapses; syn=" << static_cast<unsigned int>(syn) << "; maxSyn: M = " << static_cast<unsigned int>(M) << std::endl;
					}
					this->post_size_[neuronId] = syn;
					this->a_[neuronId] = topology->getParameterA(neuronId);
					this->b_[neuronId] = topology->getParameterB(neuronId);
					this->c_[neuronId] = topology->getParameterC(neuronId);
					this->d_[neuronId] = topology->getParameterD(neuronId);
					this->inputScaling_[neuronId] = topology->getInputScaling(neuronId);
					this->trainRate_[neuronId] = topology->getTrainRate(neuronId);
				}
				this->checkTopology();
				this->updatePreComputedData();
				this->initStateVariables();
			}

			const std::shared_ptr<const Topology> getTopology() const
			{
				this->updatePathways(this->topology_);
				return this->topology_;
			}

			void updatePathways(const std::shared_ptr<Topology>& topology) const
			{
				topology->clearPathways();
				for (const NeuronId& neuronId1 : Topology::iterator_AllNeurons())
				{
					for (Delay delay = 0; delay < D; delay++)
					{
						for (SynapseLength j = 0; j < this->synapse_size_[neuronId1][delay]; j++)
						{
							const Synapse s = this->synapse_[neuronId1][delay][j];
							const NeuronId neuronId2 = this->post_[neuronId1][s];
							const float weight = this->s_[neuronId1][s];
							topology->addPathway(neuronId1, neuronId2, delay, weight);
						}
					}
				}
			}

			void setSpikeStream(const std::shared_ptr<SpikeStream<Topology>>& spikeStream)
			{
				this->spikeStream_ = spikeStream;
			}

			void updateState()
			{
				#ifdef _USE_AVX 
				updateState_Avx<Ne + Ni + Nm>(this->v_, this->u_, this->inputCurrent_, this->inputScaling_, this->a_, this->b_);
				#endif
				#ifdef _USE_SSE2
				updateState_Sse<Ne + Ni + Nm>(this->v_, this->u_, this->inputCurrent_, this->inputScaling_, this->a_, this->b_);
				#endif
				#ifdef _USE_X64
				updateState_X64<Ne + Ni + Nm>(this->v_, this->u_, this->inputCurrent_, this->inputScaling_, this->a_, this->b_);
				#endif
				#ifdef _USE_ISPC
				updateState_ISPC<Ne + Ni + Nm>(this->v_, this->u_, this->inputCurrent_, this->inputScaling_, this->a_, this->b_);
				#endif
			}

			void updateStdp(const Ms t)
			{
				#ifdef _USE_AVX 
				updateStdp_Avx<nNeurons>(t, this->ltd, this->ltp_, N, D);
				#endif
				#ifdef _USE_SSE2
				//updateStdp_Sse<N, D>(t, this->ltd_, this->ltp_);
				updateStdp_X64<N, D>(t, this->ltd_, this->ltp_);
				#endif
				#ifdef _USE_X64
				updateStdp_X64<nNeurons>(t, this->ltd, this->ltp_, N, D);
				#endif
				#ifdef _USE_ISPC
				updateStdp_Sse<nNeurons>(t, this->ltd, this->ltp_, N, D);
				#endif
			}

			void checkTopology()
			{
				// check the contents of the post array
				for (const NeuronId& neuronId : Topology::iterator_AllNeurons())
				{
					for (Delay delay = 0; delay < D; ++delay)
					{
						for (int j = 0; j < this->synapse_size_[neuronId][delay]; ++j)
						{
							const Synapse s = this->synapse_[neuronId][delay][j];
							const NeuronId postSynapticNeuron = this->post_[neuronId][s];
							if (postSynapticNeuron == NO_NEURON_ID)
							{
								std::cerr << "checkTopology(): Error: post_[" << neuronId << "][" << static_cast<unsigned int>(s) << "] has incorrect value NO_NEURON_ID" << std::endl; throw 1;
							}
							if (postSynapticNeuron >= nNeurons)
							{
								std::cerr << "checkTopology(): Error: post_[" << neuronId << "][" << static_cast<unsigned int>(s) << "] has incorrect value " << this->post_[neuronId][s] << std::endl; throw 1;
							}
						}
					}
				}
			}

			void checkPreComputedData()
			{
				for (const NeuronId& neuronId : Topology::iterator_AllNeurons())
				{

					const unsigned int nIncommingNeurons = this->pre_size_[neuronId];
					::tools::assert::assert_msg(nIncommingNeurons < nNeurons, "preSize is too big");

					for (unsigned int i = 0; i < nIncommingNeurons; ++i)
					{
						if (this->pre_[neuronId][i].origin >= nNeurons)
						{
							std::cerr << "checkPreComputedData(): Error: i_pre_[" << neuronId << "][" << i << "] has incorrect value " << this->pre_[neuronId][i].origin << std::endl; throw 1;
						}
						if (this->pre_[neuronId][i].delay >= D)
						{
							std::cerr << "checkPreComputedData(): Error: d_pre_[" << neuronId << "][" << i << "] has incorrect value " << this->pre_[neuronId][i].delay << std::endl; throw 1;
						}
					}
				}
			}

			void updatePreComputedData()
			{
				for (const NeuronId& neuronId1 : Topology::iterator_AllNeurons())
				{
					for (int i = 0; i < spike::v1::constant::maxPreCounter; ++i)
					{
						this->pre_[neuronId1][i].origin = NO_NEURON_ID;
						this->pre_[neuronId1][i].delay = NO_DELAY;
					}
					unsigned short preCounter = 0;

					for (const NeuronId& neuronId2 : Topology::iterator_AllNeurons())
					{
						//for (NeuronId neuronId2 = 0; neuronId2 < Ne; ++neuronId2) {
						const unsigned int nOutgoingPathways = this->post_size_[neuronId2];
						for (Synapse syn1 = 0; syn1 < nOutgoingPathways; ++syn1)
						{
							if (this->post_[neuronId2][syn1] == neuronId1)
							{	// find all presynaptic neurons 
								this->pre_[neuronId1][preCounter].origin = neuronId2;		// add this neuron to the list
								for (Delay delay = 0; delay < D; ++delay)
								{			// find the delay
									for (SynapseLength j = 0; j < this->synapse_size_[neuronId2][delay]; ++j)
									{
										const Synapse syn2 = this->synapse_[neuronId2][delay][j];
										if (this->post_[neuronId2][syn2] == neuronId1)
										{
											this->pre_[neuronId1][preCounter].delay = delay;
										}
									}
								}
								this->s_pre_[neuronId1][preCounter] = &this->s_[neuronId2][syn1];
								this->sd_pre_[neuronId1][preCounter] = &this->sd_[neuronId2][syn1];

								preCounter++;
								if (preCounter > spike::v1::constant::maxPreCounter)
								{ // check for preCounter overflow
									std::cerr << "NetworkLifV1::updatePreComputedData(): neuronId1=" << neuronId1 << "; neuronId2=" << neuronId2 << "; syn1=" << static_cast<unsigned int>(syn1) << " preCounter=" << preCounter << " is larger than maxCounter " << spike::v1::constant::maxPreCounter << std::endl; throw 1;
								}
							}
						}
					}
					::tools::assert::assert_msg(preCounter < spike::v1::constant::maxPreCounter, "updatePreComputedData: preCounter is too large: preCounter=", preCounter, "; maxPreCounter=", spike::v1::constant::maxPreCounter);
					this->pre_size_[neuronId1] = preCounter;
				}
				this->checkPreComputedData();
			}

			template <bool TRAIN>
			void updateInputCurrent(const Ms t)
			{
				if (true)
				{
					memset(this->inputCurrent_, 0, sizeof(float)*N);
				}
				else
				{
					for (const NeuronId& neuronId : Topology::iterator_AllNeurons())
					{
						this->inputCurrent_[neuronId] = -2.0f;
					}
				}

				//std::cout << "train(): n_firings=" << this->n_firings << std::endl;

				// original code:
				//while (t - firings[--k][0] <D) {
				//	for (j = 0; j< delays_length[firings[k][1]][t - firings[k][0]]; j++) {
				//		i = post_[firings[k][1]][delays[firings[k][1]][t - firings[k][0]][j]];
				//		I[i] += s[firings[k][1]][delays[firings[k][1]][t - firings[k][0]][j]];
				//		if (firings[k][1] <Ne) // this spike is before postsynaptic spikes
				//			sd_[firings[k][1]][delays[firings[k][1]][t - firings[k][0]][j]] -= LTD[i];
				//	}
				//}

				for (int k = (this->spikeData_.nFirings_ - 1); k >= 0; --k)
				{

					const Delay delay = t - this->spikeData_.firingTime_[k];
					if (delay < D)
					{

						const NeuronId neuronId2 = this->spikeData_.firingNeuronId_[k]; // in the past, neuronId2 fired
						//std::cout << "Spike_Network_State: updateInputCurrent: neuron " << neuronId2 << " has fired " delay << " ms ago." << std::endl;
						::tools::assert::assert_msg(neuronId2 < nNeurons, "neuronId is too large: neuronId2=", neuronId2);

						// Loop through the list of neurons (neuronId3) that have a pathway starting in neuronId2 and that have a delay equal to delay. 
						// These neurons (neuronId3) receive a spike from neuronId2 at the current time t;

						for (SynapseLength j = 0; j < this->synapse_size_[neuronId2][delay]; ++j)
						{

							const Synapse syn = this->synapse_[neuronId2][delay][j];
							::tools::assert::assert_msg(syn < M, "synapse is too large: syn=", syn);

							const NeuronId neuronId3 = this->post_[neuronId2][syn];
							::tools::assert::assert_msg(neuronId3 < nNeurons, "neuron is too large; neuronId=", neuronId3);

							//std::cout << "Spike_Network_State: updateInputCurrent: neuron " << neuronId2 << " has fired " delay << " ms ago." << std::endl;

							// update the input current
							//this->inputCurrent_[neuronId3] += this->inputScaling_[neuronId3] * this->s_[neuronId2][syn];
							this->inputCurrent_[neuronId3] += this->s_[neuronId2][syn];

							// update the weight differential

							// original code:
							// if (firings[k][1] < Ne) sd_[firings[k][1]][delays[firings[k][1]][t - firings[k][0]][j]] -= LTD[i];

							if (TRAIN)
							{
								// update weight diffential for training
								if (Topology::isInhibitoryNeuron(neuronId2))
								{
									//do train inhibitory neurons 
								}
								else
								{ // update weights of excitatory pathways of other types of neurons
									this->sd_[neuronId2][syn] -= this->ltd_[neuronId3];
								}
							}
						}
					}
					else
					{
						break;
					}
				}
			}

			void initStateVariables()
			{
				this->initVoltageVariables();
				for (size_t i = 0; i < nNeurons; ++i)
				{
					for (size_t j = 0; j < M; ++j) this->sd_[i][j] = 0.0f; // synaptic derivatives 
					for (size_t j = 0; j < (1 + D); ++j) this->ltp_[i][j] = 0.0f;
					this->ltd_[i] = 0.0f;
				}

				this->spikeData_.nFirings_ = 1;		// spike timings
				this->spikeData_.firingTime_[0] = -D;	// put a dummy spike at -D for simulation efficiency 
				this->spikeData_.firingNeuronId_[0] = NO_NEURON_ID;	// index of the dummy spike
			}

			void initVoltageVariables()
			{
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					this->initVoltageVariable(neuronId);
				}
			}

			void initVoltageVariable(const NeuronId neuronId)
			{
				this->v_[neuronId] = -65.0f;	// coordinate (v,u)=(-65,-13) is a nodal sink for I = 3
				this->u_[neuronId] = 0.2f * this->v_[neuronId]; // -13 = this->b_[neuronId] * this->v_[neuronId]
			}

			void plotProgressInfo(TimePoint& startTime, const unsigned int sec, const unsigned int totalSeconds) const
			{
				if ((sec % (1 * 60) == 0) && (sec > 0))
				{
					const TimePoint timeNow = std::chrono::system_clock::now();
					const auto diff = timeNow - startTime;
					startTime = timeNow;

					const float avgWeightSensor = this->getAverageOutgoingWeightSensor();
					const float avgWeightExcitatory = this->getAverageOutgoingWeightExcitatory();
					const float avgMotorInputCurrent = this->getAverageMotorInputCurrent();
					const float avgExcitatoryInputCurrent = this->getAverageExcitatoryInputCurrent();

					const float avgFiringRate = (static_cast<float>(this->spikeData_.nFirings_) / nNeurons);

					std::cout << "sec " << sec << "/" << totalSeconds << ";\ttime for 1 min: " << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() << " ms;\tfiring rate " << avgFiringRate << " hz;\tavg-weight-out-exc=" << avgWeightExcitatory << ";\tavg-weigth-out-sensor=" << avgWeightSensor << ";\tavg-input-current-exc=" << avgExcitatoryInputCurrent << ";\tavg-input-current-motor=" << avgMotorInputCurrent << std::endl;
				}
			}

			template <bool TRAIN>
			void handleFiringNeurons_recordSpikes(const Ms t, const Ms spikeDataTime, SpikeSet1Sec<Ms>& spikeData)
			{
				::tools::assert::assert_msg(t >= 0, "handleFiringNeurons_train:: provided t is too small. t=", t);
				::tools::assert::assert_msg(t < 1000, "handleFiringNeurons_train:: provided t is too large.t = ", t);

				for (const NeuronId neuronId : Topology::iterator_AllNeurons())
				{
					//if (neuronId == 0) std::cout << "neuronId=" << neuronId << "; v= " << this->v_[neuronId] << "; I=" << this->inputCurrent_[neuronId] << std::endl;

					const FiringReason firingReason = this->isNeuronFired(neuronId);
					if (firingReason != FiringReason::NO_FIRE)
					{
						this->addToSpikeData(t, neuronId, firingReason);

						this->v_[neuronId] = this->c_[neuronId];	// voltage reset
						this->u_[neuronId] += this->d_[neuronId];	// recovery variable reset

						if (TRAIN)
						{
							this->ltp_[neuronId][t + D] = 0.1f;
							this->ltd_[neuronId] = 0.12f;

							for (unsigned int j = 0; j < this->pre_size_[neuronId]; ++j)
							{

								::tools::assert::assert_msg(this->pre_[neuronId][j].origin < nNeurons, "Origin is not a Neuron");
								::tools::assert::assert_msg(this->pre_[neuronId][j].delay >= 0, "Delay is too small");
								::tools::assert::assert_msg(this->pre_[neuronId][j].delay <= D, "Delay is too large");

								const NeuronId neuronId2 = this->pre_[neuronId][j].origin;
								const Ms time2 = t + D - this->pre_[neuronId][j].delay - 1;
								*this->sd_pre_[neuronId][j] += this->ltp_[neuronId2][time2];// this spike was after pre-synaptic spikes
							}
						}
						spikeData.addFiring(spikeDataTime, neuronId, firingReason);
					}
				}
			}

			template <bool TRAIN>
			void handleFiringNeurons(const Ms t)
			{
				::tools::assert::assert_msg(t >= 0, "handleFiringNeurons_train:: provided t is too small. t=", t);
				::tools::assert::assert_msg(t < 1000, "handleFiringNeurons_train:: provided t is too large.t = ", t);

				for (const NeuronId& neuronId : Topology::iterator_AllNeurons())
				{
					//if (neuronId == 0) std::cout << "neuronId=" << neuronId << "; v= " << this->v_[neuronId] << "; I=" << this->inputCurrent_[neuronId] << std::endl;

					const FiringReason firingReason = this->isNeuronFired(neuronId);

					if (firingReason != FiringReason::NO_FIRE)
					{
						//if (neuronId == 1414) {
						//	std::cout << "SpikeNetwork1::handleFiringNeurons: neuron " << neuronId << " fires at "<<t<<" ms. Reason=" << static_cast<int>(firingReason) << std::endl;
						//}
						this->addToSpikeData(t, neuronId, firingReason);

						this->v_[neuronId] = this->c_[neuronId];	// voltage reset
						this->u_[neuronId] += this->d_[neuronId];	// recovery variable reset

						if (TRAIN)
						{
							//if ((neuronId == 1414) || (neuronId == 1000)) {
							//	std::cout << "SpikeNetwork1::handleFiringNeurons: neuron " << neuronId << " fires at " << t << " ms. ltp_[" << neuronId << "][" << (t + D) << "] is set to 0.1f. Number of incomming pathways=pre_size_[" << neuronId << "]=" << this->pre_size_[neuronId] << std::endl;
							//}
							this->ltp_[neuronId][t + D] = 0.1f; // ltp decay rate is 5% per ms, see updateStdp;

							if (Topology::isSensorNeuron(neuronId))
							{
								this->ltd_[neuronId] = 0.0f;
							}
							else
							{
								this->ltd_[neuronId] = 0.12f; // ltd decay rate is 5% per ms, see updateStdp;
							}

							// original code:
							// for (j = 0; j<N_pre_[i]; j++) *sd_pre_[i][j] += LTP[I_pre_[i][j]][t + D - D_pre_[i][j] - 1];// this spike was after pre-synaptic spikes

							// explanation: Neuron with id neuronId has fired. Find all the neurons that contributed to this firing and increase their weights 
							for (unsigned int j = 0; j < this->pre_size_[neuronId]; ++j)
							{

								const NeuronId neuronId2 = this->pre_[neuronId][j].origin;
								::tools::assert::assert_msg(neuronId2 < nNeurons, "Origin is not a Neuron");

								const Delay delay = this->pre_[neuronId][j].delay;
								::tools::assert::assert_msg(delay >= 0, "Delay is too small");
								::tools::assert::assert_msg(delay <= D, "Delay is too large");
								const Ms time2 = t + D - delay - 1;

								//if ((neuronId2 == 1414) && (neuronId == 1000)) {
									//std::cout << "SpikeNetwork1::handleFiringNeurons: neuron " << neuronId << " fires at " << t << " ms. Neuron "<<neuronId2 << " contributed: sd_pre [" << neuronId << "][" << j << "] incremented with ltp_[" << neuronId2 << "][" << time2 << "]=" << this->ltp_[neuronId2][time2] << std::endl;
									////DEBUG_BREAK();
								//}

								*this->sd_pre_[neuronId][j] += this->ltp_[neuronId2][time2];// this spike was after pre-synaptic spikes
							}
						}
					}
				}
			}

			void handleFiringNeurons_train_par(const Ms t)
			{
				Profiler::start<0>();
				bool aNeuronFires = false;
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					const FiringReason firingReason = this->isNeuronFired(neuronId);
					if (firingReason != spike::FiringReason::NO_FIRE)
					{
						if (!aNeuronFires)
						{
							this->firedNeurons_.clear();
							aNeuronFires = true;
						}
						this->firedNeurons_.push_back(neuronId);
					}
				}
				if (aNeuronFires)
				{
					if (this->firedNeurons_.size() < 10)
					{
						for (const NeuronId neuronId : this->firedNeurons_)
						{
							handleFiringNeurons_train_par_static(*this, t, neuronId);
						}
					}
					else
					{
						this->results_.clear();
						if (true)
						{
							for (const NeuronId neuronId : this->firedNeurons_)
							{
								// method1: function call
								//this->results_.push_back(std::async(std::launch::async, &handleFiringNeurons_train_par_static, std::ref(*this), t, neuronId));

								// method2: with bind
								//std::function<void()> sumFunc = std::bind(&handleFiringNeurons_train_par_static, std::ref(*this), t, neuronId);
								//this->results_.push_back(std::async(std::launch::async, sumFunc));

								// method3: in lambda expression
								SpikeNetwork1 * network = this;
								this->results_.push_back(std::async(std::launch::async, [network, t, neuronId] { handleFiringNeurons_train_par_static(std::ref(*network), t, neuronId); }));
							}
						}
						else
						{
							// method4: with threadPool
							//Spike_Network_State * network = this;
							//for (const NeuronId neuronId : this->firedNeurons_) {
							//	this->results_.push_back(this->threadPool_.enqueue([network, t, neuronId] {handleFiringNeurons_train_par_static(std::ref(*network), t, neuronId); }));
							//}
						}
						for (size_t i = 0; i < this->results_.size(); ++i)
						{
							this->results_[i].get();
						}
					}
				}
				//	std::cout << "handleFiringNeurons_train_par: parallel size = " << this->results_.size() << std::endl;
				Profiler::stop<0>();
			}

			void cleanupFiringData()
			{
				unsigned int k = this->spikeData_.nFirings_ - 1; // k starts at the last fired neuron, 
				while ((1000 - this->spikeData_.firingTime_[k]) < D) k--; // count back to find the first index that is not not older than D 
				for (unsigned int i = 1; i < (this->spikeData_.nFirings_ - k); i++)
				{
					this->spikeData_.firingTime_[i] = this->spikeData_.firingTime_[k + i] - 1000; // substract one second.
					this->spikeData_.firingNeuronId_[i] = this->spikeData_.firingNeuronId_[k + i];
					this->spikeData_.firingReason_[i] = this->spikeData_.firingReason_[k + i];
				}
				this->spikeData_.nFirings_ -= k;
				this->spikeStream_->clearCaseUsage();
			}

			void cleanupLtpData()
			{
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{		// prepare for the next sec
					for (Ms time = 0; time < (D + 1); ++time)
					{
						this->ltp_[neuronId][time] = this->ltp_[neuronId][1000 + time];
					}
				}
			}

			void updateWeights()
			{
				for (const NeuronId neuronId : Topology::iterator_ExcitatoryNeurons())
				{
					this->updateWeights(neuronId);
				}
				for (const NeuronId neuronId : Topology::iterator_MotorNeurons())
				{
					this->updateWeights(neuronId);
				}
				for (const NeuronId neuronId : Topology::iterator_SensorNeurons())
				{
					this->updateWeights(neuronId);
				}
			}

			float getAverageOutgoingWeightExcitatory() const
			{
				double sum = 0;
				unsigned int counter = 0;
				for (const NeuronId& neuronId : Topology::iterator_ExcitatoryNeurons())
				{
					const float averageWeight = this->getAverageOutgoingWeight(neuronId);
					//std::cout << "Spike_Network_State::getAverageOutgoingWeightExcitatory: neuronId=" << neuronId << "; average weight " << averageWeight << std::endl;
					sum += averageWeight;
					counter++;
				}
				return static_cast<float>((counter == 0) ? 0 : (sum / counter));
			}

			float getAverageOutgoingWeightSensor() const
			{
				double sum = 0;
				unsigned int counter = 0;
				for (const NeuronId& neuronId : Topology::iterator_SensorNeurons())
				{
					const float averageWeight = this->getAverageOutgoingWeight(neuronId);
					//std::cout << "Spike_Network_State::getAverageOutgoingWeightSensor: neuronId=" << neuronId << "; average weight " << averageWeight << std::endl;
					sum += averageWeight;
					counter++;
				}
				return static_cast<float>((counter == 0) ? 0 : (sum / counter));
			}

			float getAverageOutgoingWeight(const NeuronId neuronId) const
			{
				double sum = 0;
				for (Synapse syn = 0; syn < this->post_size_[neuronId]; ++syn)
				{
					sum += this->s_[neuronId][syn];
				}
				return static_cast<float>(sum / this->post_size_[neuronId]);
			}

			float getAverageIncommingWeight(const NeuronId neuronId) const
			{
				double sum = 0;
				unsigned int counter = 0;

				for (unsigned int i = 0; i < this->pre_size_[neuronId]; ++i)
				{
					const Pre pre = this->pre_[neuronId][i];
					const NeuronId neuronId2 = pre.origin;
					const Delay d = pre.delay;
				}
				//DEBUG_BREAK(); //TODO
				for (Synapse syn = 0; syn < this->post_size_[neuronId]; ++syn)
				{
					sum += this->s_[neuronId][syn];
					counter++;
				}
				return static_cast<float>(sum / counter);
			}

			float getAverageExcitatoryInputCurrent() const
			{
				double sum = 0;
				unsigned int counter = 0;
				for (const NeuronId& neuronId : Topology::iterator_ExcitatoryNeurons())
				{
					//std::cout << "Spike_Network_State::getAverageExcitatoryInputCurrent: neuronId " << neuronId << ": " << this->inputCurrent_[neuronId] << std::endl;
					sum += this->inputCurrent_[neuronId];
					counter++;
				}
				return static_cast<float>(sum / counter);
			}

			float getAverageMotorInputCurrent() const
			{
				double sum = 0;
				unsigned int counter = 0;
				for (const NeuronId& neuronId : Topology::iterator_MotorNeurons())
				{
					//std::cout << "Spike_Network_State::getAverageMotorInputCurrent: neuronId " << neuronId << ": " << this->inputCurrent_[neuronId] << std::endl;
					sum += this->inputCurrent_[neuronId];
					counter++;
				}
				return static_cast<float>((counter == 0) ? 0 : (sum / counter));
			}

			FiringReason isNeuronFired_New(const NeuronId neuronId) const
			{
				if (Topology::isSensorNeuron(neuronId))
				{
					return isSensorNeuronFired(neuronId);
				}
				else if (Topology::isMotorNeuron(neuronId))
				{
					return isMotorNeuronFired(neuronId);
				}
				else
				{
					return isExcInhNeuronFired(neuronId);
				}
			}

			FiringReason isNeuronFired(const NeuronId neuronId) const
			{
				const NeuronDynamicType neuronDynamicType = this->spikeStream_->getNeuronDynamicType(neuronId);
				//std::cout << "isNeuronFired: neuronId = " << neuronId << "; neuronDynamicType = " << static_cast<unsigned int>(neuronDynamicType) << " (random = 0, clamped = 1, forced = 2)" << std::endl;

				switch (neuronDynamicType)
				{

					case NeuronDynamicType::RANDOM: {
						const bool neuronCanFire = (this->v_[neuronId] >= spike::v1::constant::firingThreshold);

						if (neuronCanFire)
						{
							return FiringReason::FIRE_PROPAGATED;
						}
						else
						{
							if (this->spikeStream_->hasRandomSpike(neuronId))
							{
								return FiringReason::FIRE_RANDOM;
							}
							else
							{
								return FiringReason::NO_FIRE;
							}
						}
						//break; //unreachable code
					}

					case NeuronDynamicType::CLAMPED: {
						const bool neuronClampedValue = this->spikeStream_->getClampedValue(neuronId);

						if (neuronClampedValue)
						{
							//	std::cout << "isNeuronFired: neuronId=" << neuronId << "; going to return FIRE_CLAMPED" << std::endl;
							return FiringReason::FIRE_CLAMPED;
						}
						else
						{

							// consider that the CLAMPED neurons can once in a while fire randomly.

							const bool neuronCanFire = (this->v_[neuronId] >= spike::v1::constant::firingThreshold);
							if (neuronCanFire)
							{
								//std::cout << "isNeuronFired: neuronId=" << neuronId << "; going to return FIRE_PROPAGATED_INCORRECT" << std::endl;
								return FiringReason::FIRE_PROPAGATED_INCORRECT;
							}
							else
							{
								return FiringReason::NO_FIRE;
							}
						}
						//break; //unreachable code
					}

					default: {
						//__assume(0);
						//DEBUG_BREAK();
						// This tells the optimizer that the default cannot be reached. As so, it does not have to generate
						// the extra code to check that 'p' has a value not represented by a case arm. This makes the switch 
						// run faster.
					}
				}
				#ifdef _MSC_VER
				__assume(0);
				#endif
				return FiringReason::NO_FIRE;
			}

			FiringReason isSensorNeuronFired(const NeuronId neuronId) const
			{
				if (this->spikeStream_->getClampedValue(neuronId))
				{
					return FiringReason::FIRE_CLAMPED;
				}
				else
				{
					return FiringReason::NO_FIRE;
				}
			}

			FiringReason isMotorNeuronFired(const NeuronId neuronId) const
			{
				const bool neuronCanFirePropagated = this->v_[neuronId] >= spike::v1::constant::firingThreshold;
				const bool neuronCanFireRandomly = this->spikeStream_->canFireRandomly(neuronId);
				if (neuronCanFirePropagated)
				{
					if (neuronCanFireRandomly)
					{
						return FiringReason::FIRE_PROPAGATED;
					}
					else
					{
						return FiringReason::FIRE_PROPAGATED_INCORRECT;
					}
				}
				else
				{
					if (neuronCanFireRandomly)
					{
						if (this->spikeStream_->hasRandomSpike(neuronId))
						{
							return FiringReason::FIRE_RANDOM;
						}
					}
				}
				return FiringReason::NO_FIRE;
			}

			FiringReason isExcInhNeuronFired(const NeuronId neuronId) const
			{
				const bool neuronCanFire = (this->v_[neuronId] >= spike::v1::constant::firingThreshold);
				if (neuronCanFire)
				{
					return FiringReason::FIRE_PROPAGATED;
				}
				else
				{
					if (this->spikeStream_->hasRandomSpike(neuronId))
					{
						return FiringReason::FIRE_RANDOM;
					}
				}
				return FiringReason::NO_FIRE;
			}

			const SpikeRuntimeOptions& getOptions() const
			{
				return this->spikeRuntimeOptions_;
			}

		private:

			const SpikeRuntimeOptions spikeRuntimeOptions_;
			DumperSpikes<Ms> dumperSpikes_;
			DumperTopology<Topology> dumperTopology_;
			DumperState<nNeurons> dumperState_;

			std::shared_ptr<Topology> topology_;

			TimePoint startTime_;

			void updateWeights(const NeuronId neuronId)
			{
				//std::cout << "updateWeights() neuron " << neuronId << " has " << this->post_size_[neuronId] << " outgoing pathways; M=" << M << std::endl;
				//for (Synapse syn = 0; syn<this->post_size_[neuronId]; ++syn) { //This is slower than compared to syn<M simply because almost all number of outgoing pathways equals M
				for (Synapse syn = 0; syn < M; ++syn)
				{
					const Weight2 weightIncrement = this->trainRate_[neuronId] * (0.01f + this->sd_[neuronId][syn]);

					if (false)
					{ // experiment to see if weights indeed change from zero to non zero.
						std::cout << "NetworkLifV1::train() weightIncrement for neuron " << neuronId << " -> " << this->post_[neuronId][syn] << " is " << weightIncrement << std::endl;
						if ((this->s_[neuronId][syn] == 0) && (weightIncrement > 0))
						{
							std::cout << "updateWeights() neuron " << neuronId << " to " << this->post_[neuronId][syn] << "(syn=" << syn << ") is going from zero to " << weightIncrement << std::endl;
						}
					}
					this->s_[neuronId][syn] += weightIncrement;

					/*
					if (Topology::isSensorNeuron(neuronId)) {
					//final NeuronId incommingNeuron = this->pre_[]
					if (this->sd_[neuronId][syn] != 0) {
					std::cout << "Spike_Network_State::updateWeights: neuronId=" << neuronId << "; weightDelta=" << weightDelta << "; trainRate=" << this->trainRate_[neuronId] << std::endl;
					}
					}
					*/


					if (this->s_[neuronId][syn] > spike::v1::constant::maxEfficacy) this->s_[neuronId][syn] = spike::v1::constant::maxEfficacy;
					if (this->s_[neuronId][syn] < 0)
					{
						this->s_[neuronId][syn] = 0.0;
						//std::cout << "updateWeights() neuron " << neuronId << " to " << this->post_[neuronId][syn] << " is set to zero" << std::endl;
					}
					this->sd_[neuronId][syn] *= 0.9f;

					if ((neuronId == 1414) && (syn == 0))
					{
						//std::cout << "Spike_Network_State::updateWeights: neuronId=" << neuronId << "; syn=" << static_cast<int>(syn) << "; weightIncrement=" << weightIncrement << "; s[" << neuronId << "][" << static_cast<int>(syn) << "]=" << this->s_[neuronId][syn] << "; sd_[" << neuronId << "][" << static_cast<int>(syn) << "]=" << this->sd_[neuronId][syn] << std::endl;
					}
				}
			}

			void addToSpikeData(const Ms t, const NeuronId neuronId, const FiringReason firingReason)
			{
				this->spikeData_.addFiring(t, neuronId, firingReason);
			}
		}; // end Spike_Network_State
	}
}