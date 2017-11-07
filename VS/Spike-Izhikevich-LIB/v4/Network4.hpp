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

#include <string>
#include <sstream>	// for ostringstream
#include <array>
#include <vector>
#include <tuple>
#include <memory>
#include <chrono>

#include "../../Spike-Tools-LIB/DumperTopology.hpp"
#include "../../Spike-Tools-LIB/SpikeTypes.hpp"
#include "../../Spike-Tools-LIB/Kernel.hpp"

#include "../../Spike-Tools-LIB/intrin.ipp"

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"
#include "../../Spike-Izhikevich-LIB/Topology.hpp"

#include "../../Spike-Izhikevich-LIB/v4/SpikeEpspContainer4.hpp"
#include "../../Spike-Izhikevich-LIB/v4/DumperState4.hpp"
#include "../../Spike-Izhikevich-LIB/v4/DumperSpikes4.hpp"
#include "../../Spike-Izhikevich-LIB/v4/DumperWeigthDelta4.hpp"
#include "../../Spike-Izhikevich-LIB/v4/SpikeDataSetMatlab4.hpp"
#include "../../Spike-Izhikevich-LIB/v4/Spikes4.hpp"
#include "../../Spike-Izhikevich-LIB/v4/Synapses4.hpp"


namespace spike
{
	namespace v4
	{
		using namespace spike::tools;
		using namespace spike::dataset;
		using namespace ::tools::intrin;

		template <typename Topology_i, size_t nSubMs_i>
		class Network4
		{
		public:

			using TimePoint = std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration>;
			using Topology = Topology_i;

			static const size_t Ne = Topology::Ne;
			static const size_t Ni = Topology::Ni;
			static const size_t Ns = Topology::Ns;
			static const size_t Nm = Topology::Nm;
			static const size_t nNeurons = Topology::nNeurons;
			static const size_t N = Topology::N;

			static const size_t nSubMs = nSubMs_i;

			static const size_t D = Topology::D;
			static const size_t M = Topology::M;

			static constexpr float alpha_plus = 0.03125f;
			static constexpr float alpha_minus = 0.50f * alpha_plus;//0.85f * alpha_plus;

			static constexpr float tau_plus = 15;//16.8f;
			static constexpr float tau_minus = 20;//33.7f;
			static constexpr float learnSpeed = 0.0001f;


			static const bool traceNeuronOn = false;
			static const NeuronId traceNeuronId = 495;

			// constructor
			Network4() = default;

			// constructor
			Network4(const SpikeRuntimeOptions& spikeRuntimeOptions)
				: spikeRuntimeOptions_(spikeRuntimeOptions)
				, dumperSpikes_(DumperSpikes4(spikeRuntimeOptions))
				, dumperState_(DumperState4<nNeurons, nSubMs>(spikeRuntimeOptions))
				, dumperTopology_(DumperTopology<Topology>(spikeRuntimeOptions))
				, dumperWeightDelta_(DumperWeightDelta4(spikeRuntimeOptions))
			{
				this->nSpikesThisSecond_ = 0;
				for (size_t i = 0; i < N; ++i)
				{
					this->lastSpikeTime_[i] = -1000;
					this->secondLastSpikeTime_[i] = -1000;
				}

				this->spikeEpspContainer4_.setOutputFilename(tempDir + "/v4-masq/epsp.txt");
			}

			void setSpikeDataSet(const std::shared_ptr<SpikeDataSetMatlab4<Ne, nSubMs>>& dataset)
			{
				this->spikeDataSetMatlab_ = dataset;
			}

			void setTopology(const std::shared_ptr<Topology>& topology)
			{
				this->topology_ = topology;
				this->synapses_.init(topology);

				for (const NeuronId neuronId : Topology::iterator_AllNeurons())
				{
					this->a_[neuronId] = topology->getParameterA(neuronId);
					this->b_[neuronId] = topology->getParameterB(neuronId);
					this->c_[neuronId] = topology->getParameterC(neuronId);
					this->d_[neuronId] = topology->getParameterD(neuronId);
					this->trainRate_[neuronId] = topology->getTrainRate(neuronId);

					this->v_[neuronId] = -65.0f;	// coordinate (v,u)=(-65,-13) is a nodal sink for I = 3
					this->u_[neuronId] = 0.2f * this->v_[neuronId]; // -13 = this->b[neuronId] * this->v[neuronId]
				}
			}

			const std::shared_ptr<const Topology> getTopology()
			{
				this->topology_->clearPathways();
				for (const NeuronId& origin : Topology::iterator_AllNeurons())
				{
					for (Delay d = 0; d < static_cast<Delay>(D); ++d)
					{
						for (const NeuronId destination : this->synapses_.getDestinations(origin, d))
						{
							const float weight = this->synapses_.getWeight(origin, destination);
							this->topology_->addPathway(origin, destination, d, weight);
						}
					}
				}
				return this->topology_;
			}

			void setSpikeStream(const std::shared_ptr<SpikeStream<Topology>>& spikeStream)
			{
				this->spikeStream_ = spikeStream;
			}

			void run(const unsigned int nSeconds, const bool useConfusionMatrix, const bool plotProgress)
			{
				initState(this->st_, this->ic_);
				this->spikes_.clear();
				this->startTime_ = std::chrono::system_clock::now();

				for (unsigned int sec = 0; sec < nSeconds; ++sec)
				{
					const bool dumpSpikes = this->dumperSpikes_.dumpTest(sec);
					const bool dumpState = this->dumperState_.dumpTest(sec);
					const bool dumpWeightDelta = this->dumperWeightDelta_.dumpTest(sec);

					if (dumpWeightDelta)
					{
						if (dumpSpikes)
						{
							((dumpState) ? this->run1Second<true, true, true>(sec, nSeconds, useConfusionMatrix, plotProgress) : this->run1Second<true, false, true>(sec, nSeconds, useConfusionMatrix, plotProgress));
						}
						else
						{
							((dumpState) ? this->run1Second<false, true, true>(sec, nSeconds, useConfusionMatrix, plotProgress) : this->run1Second<false, false, true>(sec, nSeconds, useConfusionMatrix, plotProgress));
						}
					}
					else
					{
						if (dumpSpikes)
						{
							((dumpState) ? this->run1Second<true, true, false>(sec, nSeconds, useConfusionMatrix, plotProgress) : this->run1Second<true, false, false>(sec, nSeconds, useConfusionMatrix, plotProgress));
						}
						else
						{
							((dumpState) ? this->run1Second<false, true, false>(sec, nSeconds, useConfusionMatrix, plotProgress) : this->run1Second<false, false, false>(sec, nSeconds, useConfusionMatrix, plotProgress));
						}
					}
				}
			}

		private:

			SpikeRuntimeOptions spikeRuntimeOptions_;
			std::shared_ptr<Topology> topology_;

			Synapses4<Topology> synapses_;
			Spikes4<nNeurons, nSubMs> spikes_;

			SpikeNetworkPerformance<Topology, Ms> spikeNetworkPerformance_;
			std::shared_ptr<SpikeStream<Topology>> spikeStream_;

			SpikeEpspContainer4 spikeEpspContainer4_;
			DumperSpikes4 dumperSpikes_;
			DumperState4<nNeurons, nSubMs> dumperState_;
			DumperTopology<Topology> dumperTopology_;
			DumperWeightDelta4 dumperWeightDelta_;

			TimePoint startTime_;
			std::shared_ptr<SpikeDataSetMatlab4<Ne, nSubMs>> spikeDataSetMatlab_;


			unsigned int nSpikesThisSecond_;

			float __declspec(align(4)) lastSpikeTime_[N];
			float __declspec(align(4)) secondLastSpikeTime_[N];

			int __declspec(align(4)) st_[N];
			float __declspec(align(4)) ic_[N * nSubMs];

			float __declspec(align(4)) trainRate_[N];

			float __declspec(align(4)) v_[N];
			float __declspec(align(4)) u_[N];

			float __declspec(align(4)) a_[N];
			float __declspec(align(4)) b_[N];
			float __declspec(align(4)) c_[N];
			float __declspec(align(4)) d_[N];


			template <bool dumpSpikes, bool dumpState, bool dumpWeightDelta>
			void run1Second(
				const unsigned int sec,
				const unsigned int nSeconds,
				const bool useConfusionMatrix,
				const bool plotProgress)
			{
				if (dumpSpikes) this->dumperSpikes_.clear();

				for (unsigned int ms = 0; ms < 1000; ++ms)
				{
					this->updateIC<dumpSpikes>(ms, sec);
					this->updateState<dumpState>(ms, sec);
					this->updateSpikes<dumpSpikes, dumpWeightDelta>(this->st_, ms, sec);
					this->ltd<dumpWeightDelta>(ms);
					this->updateWeight();
					this->spikes_.advance1Ms();
				}
				//this->incWeight(-0.02f);
				//this->updateWeight();

				if (plotProgress)
				{
					this->plotProgressInfo(this->startTime_, sec, nSeconds);
				}

				this->resetSecond();

				if (this->dumperTopology_.dumpTest(sec)) this->dumperTopology_.dump(sec, "newCode4", this->getTopology());
				if (dumpSpikes) this->dumperSpikes_.dump(sec, "newCode4");
				if (dumpState) this->dumperState_.dump(sec, "newCode4");
				if (dumpWeightDelta) this->dumperWeightDelta_.dump(sec, "newCode4");
			}

			template <bool dumpSpikes, bool dumpWeightDelta>
			void updateSpikes(
				const int st[N],
				const unsigned int currentTimeInMs,
				const unsigned int sec)
			{
				std::vector<std::tuple<NeuronId, float>> spikedNeurons;

				//std::cout << "udpateSpikes:"<< std::endl;
				const __m128i all_one = _mm_setones_si128();

				for (size_t i = 0; i < N; i += 4)
				{
					__m128i sti = _mm_load_epi32(&st[i]); // spike time i
					if (_mm_test_has_zeros(sti, all_one))
					{ // test if at least one of the neurons has fired
						for (int j = 0; j < 4; ++j)
						{
							const unsigned int spikeTimeSubMs = _mm_cvtsi128_si32(sti);
							if (spikeTimeSubMs == 0xFFFFFFFF)
							{
								// no spike
							}
							else if (spikeTimeSubMs < nSubMs)
							{
								::tools::assert::assert_msg(spikeTimeSubMs < nSubMs, "spike::v4::Network4: updateSpikes: spikeTimeSubMs=", spikeTimeSubMs, " is larger than nSubMs=", nSubMs);
								const NeuronId neuronId = static_cast<NeuronId>(i + j);
								if (neuronId < nNeurons)
								{
									const float spikeTimeInMsFloat = currentTimeInMs + (static_cast<float>(spikeTimeSubMs) / nSubMs);
									spikedNeurons.push_back(std::make_tuple(neuronId, spikeTimeInMsFloat));
									this->handleSpike<dumpSpikes>(neuronId, spikeTimeInMsFloat, sec);
								}
							}
							else
							{
								std::cout << "spike::v4::Network4::updateSpikes: invalid subMs spiketime " << spikeTimeSubMs << std::endl;
							}
							sti = _mm_ror_epi32(sti);
						}
					}
				}

				for (const std::tuple<NeuronId, float>& tuple : spikedNeurons)
				{
					this->ltp<dumpWeightDelta>(std::get<0>(tuple), std::get<1>(tuple));
				}
			}

			template <bool dumpSpikes>
			void handleSpike(
				const NeuronId neuronId,
				const float spikeTimeInMsFloat,
				const unsigned int sec)
			{
				this->nSpikesThisSecond_++;
				if (dumpSpikes)
				{
					this->dumperSpikes_.store(spikeTimeInMsFloat, neuronId, FiringReason::FIRE_PROPAGATED);
				}

				//printf("spike: at %4.2f ms neuron %u spikes.\n", spikeTimeInMsFloat, neuronId);
				if (neuronId >= Ne)
				{
					this->printProgressionResults(neuronId, spikeTimeInMsFloat, sec);
				}

				//2] update last fire time of firing neuron
				this->secondLastSpikeTime_[neuronId] = this->lastSpikeTime_[neuronId];
				this->lastSpikeTime_[neuronId] = spikeTimeInMsFloat;

				//3] update the input current
				const NeuronId origin = neuronId;

				for (size_t d = 0; d < Topology::D; ++d)
				{
					for (const NeuronId destination : this->synapses_.getDestinations(origin, static_cast<Delay>(d)))
					{

						const float arrivalTimeInMs = spikeTimeInMsFloat + d;

						//if (origin >= 1000) {
						//	std::cout << "handleSpike: origin=" << origin << "; destination=" << destination << "; delay=" << d << "; arrivalTimeInMs = " << arrivalTimeInMs << std::endl;
						//}
						//2: for LTD: store at what time a spike is received at destination
						//3: set the last deliver time of this spike to the receiving neuron
						this->spikes_.addSpike(origin, destination, arrivalTimeInMs);
					}
				}
			}

			void printProgressionResults(const NeuronId neuronId, const float spikeTimeInMsFloat, const unsigned int sec)
			{
				this->spikeEpspContainer4_.storeSpikeEvent(neuronId, sec + (spikeTimeInMsFloat / 1000));

				const float percentageDone = 0;// (timeInMs / this->network_.t_max_inMs) * 100;
				const float spikeTime = spikeTimeInMsFloat + (1000 * sec);
				bool firedInPattern = false;
				for (const CaseId caseId : this->spikeDataSetMatlab_->getCaseIds())
				{
					const float latency = this->spikeDataSetMatlab_->latency(spikeTime, caseId);
					if (latency > 0.0f)
					{
						firedInPattern = true;
						printf("at %.3f ms (%.1f%%) neuron %u: caseId %d, latency %f\n", spikeTime, percentageDone, neuronId, caseId.val, latency);
					}
				}
				if (!firedInPattern)
				{
					printf("at %.3f ms (%.1f%%) neuron %u: caseId -, latency -\n", spikeTime, percentageDone, neuronId);
				}
			}


			template <bool dumpSpikes>
			void updateIC(const unsigned int currentTimeInMs, const unsigned int currentTimeInSec) //currentTimeInMs is only needed for spike dumping
			{
				//1] clear old ic
				memset(this->ic_, 0, N*nSubMs * sizeof(float));

				if (false)
				{
					//2] add random input current
					for (int k = 0; k < 1; ++k)
					{
						const NeuronId randNeuron = ::tools::random::rand_int32(nNeurons);
						const int spikeTimeSubMs = ::tools::random::rand_int32(nSubMs);
						const float current = 50; // 10 does not give a spike; 20 gives a 10 ms delayed spike; 50 gives a 2 ms delayed spike; 100 gives a 1 ms delay
						this->ic_[indexIC(randNeuron, spikeTimeSubMs)] = current * nSubMs;

						if (dumpSpikes)
						{
							const float spikeTimeInMsFloat = currentTimeInMs + (static_cast<float>(spikeTimeSubMs) / nSubMs);
							this->dumperSpikes_.store(spikeTimeInMsFloat, randNeuron, FiringReason::FIRE_RANDOM);
						}
					}
				}

				//2] propagated input current
				for (NeuronId destination = Ne; destination < nNeurons; ++destination)
				{
					const std::vector<std::tuple<NeuronId, int>>& incommingSpikes = this->spikes_.getIncommingSpikesCurrentMs(destination);

					for (const std::tuple<NeuronId, int>& tuple : incommingSpikes)
					{
						const NeuronId origin = std::get<0>(tuple);
						const int spikeTimeSubMs = std::get<1>(tuple);
						const float w = this->synapses_.getWeight(origin, destination)*0.0060f;

						//if (w < 0) {
						//	printf("updateIC: adding ic=%f to destination neuron %u at currentTimeInMs %u; origin neuron %u\n", w, destination, currentTimeInMs, origin);
						//}
						//if (std::isnan(w)) {
						//printf("updateIC: adding ic=%f to destination neuron %u at currentTimeInMs %u; origin neuron %u\n", w, destination, currentTimeInMs, origin);
						//}

						//printf("updateIC: adding ic=%f to neuron %u at subMs %i\n", w, destination, subMs);
						this->ic_[indexIC(destination, spikeTimeSubMs)] += (w * nSubMs);
					}
				}
			}

			static void initState(
				int st[N],	// spikeTime
				float ic[N * nSubMs])
			{
				for (size_t i = 0; i < N; ++i)
				{
					st[i] = static_cast<int>(0xFFFFFFFF);
					for (size_t j = 0; j < nSubMs; ++j)
					{
						ic[(i*nSubMs) + j] = 0;
					}
				}
			}

			template <bool dumpWeightDelta>
			void ltp(const NeuronId neuronId, const float spikeTimeInMsFloat)
			{
				for (const NeuronId& contributingNeuronId : this->synapses_.getOrigins(neuronId))
				{

					const float arrivalTime = this->spikes_.getLastArrivalTimeCurrentMs(contributingNeuronId, neuronId);
					if (traceNeuronOn && ((contributingNeuronId == traceNeuronId) || (neuronId == traceNeuronId)))
					{
						std::cout << "spike::v4::Network4::ltp: A: neuron " << contributingNeuronId << " contributed to neuron " << neuronId << " at " << arrivalTime << " ms; spikeTimeInMsFloat=" << spikeTimeInMsFloat << std::endl;
					}

					//std::cout << "spike::v4::Network4::handleSpike: A: contributionTime=" << contributionTime << "; spikeTimeInMsFloat=" << spikeTimeInMsFloat << std::endl;
					const float wD = spike::tools::stdp(arrivalTime, spikeTimeInMsFloat, alpha_plus, alpha_minus, tau_plus, tau_minus);
					if (wD > 1e-8)
					{
						const NeuronId origin = contributingNeuronId;
						const NeuronId destination = neuronId;
						const float timeTooEarly = spikeTimeInMsFloat - arrivalTime;
						this->synapses_.incWeightDelta(contributingNeuronId, neuronId, wD);

						if (dumpWeightDelta) this->dumperWeightDelta_.store_WeightDelta(spikeTimeInMsFloat, contributingNeuronId, neuronId, wD);

						if (traceNeuronOn && ((origin == traceNeuronId) || (destination == traceNeuronId)))
						{
							printf("spike::v4::Network4::ltp: %4u->%4u: spike time (of %4u) = %9.6f; arrival time = %9.6f; time before spike = %9.6f; wD = %8.6f; \n", origin, destination, destination, spikeTimeInMsFloat, arrivalTime, timeTooEarly, wD);
						}
					}
				}
			}

			template <bool dumpWeightDelta>
			void ltd(const unsigned int currentMs)
			{
				for (NeuronId destination = 0; destination < nNeurons; ++destination)
				{
					const std::vector<std::tuple<NeuronId, int>>& incommingSpikes = this->spikes_.getIncommingSpikesCurrentMs(destination);
					for (const std::tuple<NeuronId, int>& tuple : incommingSpikes)
					{
						const NeuronId origin = std::get<0>(tuple);
						const int subMs = std::get<1>(tuple);

						// get the time that this destination neuron has spiked
						float lastSpikeTime = this->lastSpikeTime_[destination];
						const float subMsFloat = (static_cast<float>(subMs) / nSubMs);
						//if (subMsFloat > 1) {
						//	std::cout << "spike::v4::Network4:ltd: subMsFloat=" << subMsFloat << std::endl;
						//	//DEBUG_BREAK();
						//}
						const float arrivalTime = currentMs + subMsFloat;

						if (lastSpikeTime >= arrivalTime)
						{
							lastSpikeTime = this->secondLastSpikeTime_[destination];
							if (lastSpikeTime >= arrivalTime)
							{
								//DEBUG_BREAK();
							}
						}
						const float wD = spike::tools::stdp(arrivalTime, lastSpikeTime, alpha_plus, alpha_minus, tau_plus, tau_minus);
						if (wD < -1e-8)
						{
							this->synapses_.decWeightDelta(origin, destination, wD);
							if (dumpWeightDelta) this->dumperWeightDelta_.store_WeightDelta(arrivalTime, origin, destination, wD);

							if (traceNeuronOn && ((origin == traceNeuronId) || (destination == traceNeuronId)))
							{
								const float timeTooLate = arrivalTime - lastSpikeTime;
								printf("spike::v4::Network4::ltd: %4u->%4u: last spike time (of %4u) = %.6f; arrivalTime = %.6f; timeTooLate = %8.6f; wD = %.6f; currentMs=%u\n", origin, destination, destination, lastSpikeTime, arrivalTime, timeTooLate, wD, currentMs);
							}
						}
					}
				}
			}

			void resetSecond()
			{
				this->synapses_.resetSecond();
				this->spikes_.resetSecond();

				this->nSpikesThisSecond_ = 0;
				// substract 1 second from the last spike times
				for (const NeuronId neuronId : Topology::iterator_AllNeurons())
				{
					this->lastSpikeTime_[neuronId] -= 1000;
					this->secondLastSpikeTime_[neuronId] -= 1000;
				}
			}

			void plotProgressInfo(TimePoint& startTime, const unsigned int sec, const unsigned int totalSeconds) const
			{
				if ((sec % (1 * 1) == 0) && (sec > 0))
				{
					const TimePoint timeNow = std::chrono::system_clock::now();
					const auto diff = timeNow - startTime;
					startTime = timeNow;

					const float avgWeightOutSensor = this->synapses_.getAverageOutgoingWeightSensor();
					const float avgWeightOutExcitatory = this->synapses_.getAverageOutgoingWeightExcitatory();
					const float avgWeightInMotor = this->synapses_.getAverageIncommingWeightMotor();
					const float avgFiringRate = (static_cast<float>(this->nSpikesThisSecond_) / nNeurons);

					std::cout << "sec " << sec << "/" << totalSeconds << ";\ttime for 1 min: " << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() << " ms;\tfiring rate " << avgFiringRate << " hz;\tavg-w-out-exc=" << avgWeightOutExcitatory << ";\tavg-w-out-sensor=" << avgWeightOutSensor << ";\tavg-w-in-motor=" << avgWeightInMotor << std::endl;
				}
			}

			static size_t indexIC(const size_t neuronId, const size_t subMs)
			{
				if (subMs >= nSubMs)
				{
					std::cout << "spike::v4::Network4::indexIC: subMs (" << subMs << ") is too large. nSubMs = " << nSubMs << std::endl;
					//DEBUG_BREAK();
				}
				return neuronId + (subMs * N);
			}

			void incWeightAll(const float delta)
			{
				this->synapses_.incWeight(delta);
			}

			void incWeight(const NeuronId origin, const NeuronId destination, const float delta)
			{
				//if (origin == 0) std::cout << "incWeight: origin=" << origin << "; destination=" << destination << "; delta=" << delta << std::endl;

				if (std::isnan(delta))
				{
					return;
					//std::cout << "incWeight: delta="<<delta<<": origin=" << origin << "; destination=" << destination << std::endl;
					////DEBUG_BREAK();
				}
				float weightInc = (delta * learnSpeed);

				//std::cout << "incWeight: weightInc=" << weightInc << "; oldWeight = " << oldWeight << "; delta = " << delta << std::endl;
				if (weightInc > 2.0f)
				{
					printf("spike::v4::Network4::incWeight: WARNING: large delta: origin=%u; destination=%u; weightInc=%f; delta=%f\n", origin, destination, weightInc, delta);
					weightInc = 2.0f;
				}
				else if (weightInc < -2.0f)
				{
					printf("spike::v4::Network4::incWeight: WARNING: large delta: origin=%u; destination=%u; weightInc=%f; delta=%f\n", origin, destination, weightInc, delta);
					weightInc = -2.0f;
				}

				const float oldWeight = this->synapses_.getWeight(origin, destination);
				float newWeight = oldWeight + weightInc;
				if (newWeight < 0)
				{
					newWeight = 0;
				}
				else if (newWeight > 10)
				{
					newWeight = 10;
				}

				this->synapses_.setWeight(origin, destination, newWeight);
				//std::cout << "incWeight: " << neuronId << "->" << receivingNeuronId << ": weightInc=" << weightInc << "; old Weight=" << oldWeight << "; new Weight=" << this->weights_[receivingNeuronId][neuronId] << std::endl;
			}

			void updateWeight()
			{
				const bool useWeightChangeBalancing = false;
				if (useWeightChangeBalancing)
				{
					const std::array<double, 2> averageWeightDeltaPlusMin = this->getAverageWeightDeltaPlusMin();
					double balance = averageWeightDeltaPlusMin[0] / averageWeightDeltaPlusMin[1];
					if (std::isnan(balance))
					{
						return;
					}
					//if ((sec % (1 * 1) == 0) && (sec > 0)) {
					//	std::cout << "updateWeight: sec=" << sec << "; average averagePlus=" << averageWeightDeltaPlusMin[0] << "; average averageMin=" << averageWeightDeltaPlusMin[1] << "; balance=" << balance << std::endl;
					//}

					//for (const NeuronId& destination : Topology::iterator_AllNeurons()) {
					for (NeuronId destination = Ne; destination < nNeurons; ++destination)
					{
						for (const NeuronId& origin : this->synapses_.getOrigins(destination))
						{
							if (!Topology::isInhibitoryNeuron(origin))
							{
								const std::array<float, 2> deltaArray = this->synapses_.getWeightDeltaPlusMin(origin, destination);
								const double delta = deltaArray[0] - (balance * deltaArray[1]);
								this->incWeight(origin, destination, static_cast<float>(delta));
							}
						}
					}
				}
				else
				{
					//for (const NeuronId& destination : Topology::iterator_AllNeurons()) {
					for (NeuronId destination = Ne; destination < nNeurons; ++destination)
					{
						for (const NeuronId& origin : this->synapses_.getOrigins(destination))
						{
							if (!Topology::isInhibitoryNeuron(origin))
							{
								const float delta = this->synapses_.getWeightDelta(origin, destination);
								this->incWeight(origin, destination, delta);
							}
						}
					}
				}
				this->synapses_.clearWeightDelta();
			}

			std::array<double, 2> getAverageWeightDeltaPlusMin() const
			{
				double sum_plus = 0;
				double sum_min = 0;
				unsigned int count = 0;

				for (const NeuronId& destination : Topology::iterator_AllNeurons())
				{
					for (const NeuronId& origin : this->synapses_.getOrigins(destination))
					{
						if (!Topology::isInhibitoryNeuron(origin))
						{
							const std::array<float, 2> deltaPlusMin = this->synapses_.getWeightDeltaPlusMin(origin, destination);
							sum_plus += deltaPlusMin[0];
							sum_min += deltaPlusMin[1];
							count++;
						}
					}
				}
				const double averagePlus = (count > 0) ? (sum_plus / count) : 0;
				const double averageMin = (count > 0) ? (sum_min / count) : 0;
				return{ averagePlus, averageMin };
			}

			template <bool dumpState>
			void updateState(const unsigned int currentTimeInMs, const unsigned int currentTimeInSec)
			{
				const bool useSSE = false;

				// update spike time of input neurons
				const unsigned int currentTimeX = currentTimeInMs + (1000 * currentTimeInSec);
				for (NeuronId i = 0; i < Ne; ++i)
				{
					std::tuple<bool, short> tuple = this->spikeDataSetMatlab_->getInputSpike(i, currentTimeX);
					this->st_[i] = (std::get<0>(tuple)) ? std::get<1>(tuple) : static_cast<int>(0xFFFFFFFF);

					if (traceNeuronOn && ((i == traceNeuronId) && (std::get<0>(tuple))))
					{
						const double spikeTime = (currentTimeInSec * 1000) + currentTimeInMs + (static_cast<double>(std::get<1>(tuple)) / nSubMs);
						printf("spike::v4::Network4::updateState: neuron %u spikes at %f ms\n", i, spikeTime);
					}
				}

				// update state of other neurons
				if (useSSE)
				{
					updateState_Sse<dumpState>(this->v_, this->u_, this->st_, currentTimeInMs, this->ic_, this->a_, this->b_, this->c_, this->d_, this->dumperState_);
				}
				else
				{
					if (nSubMs == 1)
					{
						//updateState_X64_Original<dumpState>(this->v_, this->u_, this->st_, ms, this->ic_, this->a_, this->b_, this->c_, this->d_, this->dumperState_);
					}
					else
					{
						updateState_X64<dumpState>(this->v_, this->u_, this->st_, currentTimeInMs, this->ic_, this->a_, this->b_, this->c_, this->d_, this->dumperState_);
					}
				}
				/*
				for (NeuronId i = Ne; i < nNeurons; ++i) {
					if (::tools::getRandomInt_incl<0, 1000>() == 0) {
						this->st_[i] = ::tools::getRandomInt_excl<0, nSubMs>();
					}
				}
				*/
			}

			template <bool dumpState>
			static inline void updateState_Sse(
				float v[N],
				float u[N],
				int st[N],	// spikeTimeInSubMs
				const int currentTimeInMs, // only needed for dumping
				const float ic[N * nSubMs],
				const float a[N],
				const float b[N],
				const float c[N],
				const float d[N],
				DumperState4<nNeurons, nSubMs>& dumperState)
			{
				const __m128 threshold_i = _mm_set1_ps(30);
				const __m128i one = _mm_set1_epi32(1);
				const __m128i all_one = _mm_setones_si128();

				const __m128 c1 = _mm_set1_ps(1.0f / nSubMs);
				const __m128 c_04 = _mm_set1_ps(0.04f);
				const __m128 c_5 = _mm_set1_ps(5.0f);
				const __m128 c_140 = _mm_set1_ps(140.0f);

				for (size_t i = 0; i < N; i += 4)
				{

					__m128 vi = _mm_load_ps(&v[i]);
					__m128 ui = _mm_load_ps(&u[i]);

					const __m128 ai = _mm_load_ps(&a[i]);
					const __m128 bi = _mm_load_ps(&b[i]);
					const __m128 ci = _mm_load_ps(&c[i]);
					const __m128 di = _mm_load_ps(&d[i]);

					#if _DEBUG
					//printf("v[%i]=%s\n", i, ::tools::toString_f32(vi).c_str());
					//printf("u[%i]=%s\n", i, ::tools::toString_f32(ui).c_str());
					//printf("a[%i]=%s\n", i, ::tools::toString_f32(ai).c_str());
					//printf("b[%i]=%s\n", i, ::tools::toString_f32(bi).c_str());
					//printf("c[%i]=%s\n", i, ::tools::toString_f32(ci).c_str());
					//printf("d[%i]=%s\n", i, ::tools::toString_f32(di).c_str());
					#endif 

					__m128i cti = _mm_setzero_si128();			// current time
					__m128i sti = all_one;	// set spike time to zero

					for (size_t j = 0; j < nSubMs; ++j)
					{

						//std::cout << "i=" << i << "; j=" << j << std::endl;

						const __m128 ici = _mm_load_ps(&ic[indexIC(i, j)]); // warning: not unit stride
						//printf("ic[%i][%i]=%s\n", i, j, ::tools::toString_f32(ici).c_str());


						//////////////////////////////////////////
						//	v[i] += (1/nSubMs) * ((((0.04f * v[i]) + 5) * v[i]) + 140 - u[i] + ic[i][j]);
						vi = _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(vi, c_04), c_5), vi), _mm_add_ps(_mm_sub_ps(ici, ui), c_140)), c1), vi);

						//////////////////////////////////////////
						//	u[i] += (1/nSubMs) * a[i] * ((b[i] * v[i]) - u[i]);
						ui = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps(_mm_mul_ps(vi, bi), ui), ai), c1), ui);


						if (dumpState)
						{
							for (size_t k = 0; k < 4; ++k)
							{
								const NeuronId n = static_cast<NeuronId>(i + k);
								if (n >= 1000)
								{
									const float vik = ::tools::intrin::priv::get_f32(vi, k);
									const float uik = ::tools::intrin::priv::get_f32(ui, k);
									const float icik = ::tools::intrin::priv::get_f32(ici, k);
									dumperState.store(n, currentTimeInMs, static_cast<int>(j), vik, uik, icik);
								}
							}
						}

						//////////////////////////////////////////
						// handle update state after spiking
						const __m128 mi = _mm_cmpge_ps(vi, threshold_i); // c = (a > b) 
						if (_mm_test_has_ones(mi, all_one))
						{

							//printf("a neuron has spiked! i=%i\n", i);
							//printf("mi[%i]=%s\n", i, ::tools::toString_f32(mi).c_str());
							//printf("v[%i]=%s\n", i, ::tools::toString_f32(vi).c_str());
							//printf("u[%i]=%s\n", i, ::tools::toString_f32(ui).c_str());

							vi = _mm_or_ps(_mm_andnot_ps(mi, vi), _mm_and_ps(mi, ci)); // voltage reset
							ui = _mm_add_ps(ui, _mm_and_ps(mi, di));	// u += d;	// recovery variable reset
							sti = _mm_or_si128(_mm_andnot_si128(_mm_castps_si128(mi), sti), _mm_and_si128(_mm_castps_si128(mi), cti));
						}

						cti = _mm_add_epi32(cti, one); // increment currentTime_i
					}

					_mm_store_epi32(&st[i], sti);
					_mm_store_ps(&u[i], ui);
					_mm_store_ps(&v[i], vi);
				}
			}

			template <bool dumpState>
			static inline void updateState_X64(
				float v[N],
				float u[N],
				int st[N],	// spikeTimeInSubMs
				const unsigned int currentTimeInMs, // only needed for dumping
				const float ic[N * nSubMs],
				const float a[N],
				const float b[N],
				const float c[N],
				const float d[N],
				DumperState4<nNeurons, nSubMs>& dumperState)
			{

				const bool checkForFutureSpikes = true;
				const int nMsFutureCheck = 5;

				const float threshold_i = 30;
				const float c1 = 1.0f / nSubMs;

				for (size_t i = Ne; i < nNeurons; ++i)
				{

					float vi = v[i];
					float ui = u[i];

					const float ai = a[i];
					const float bi = b[i];
					const float ci = c[i];
					const float di = d[i];

					int sti = static_cast<int>(0xFFFFFFFF);

					for (size_t j = 0; j < nSubMs; ++j)
					{

						//std::cout << "i=" << i << "; j=" << j << std::endl;

						const float ici = ic[indexIC(i, j)]; // warning: not unit stride

						float vi2 = vi;
						vi2 += c1 * ((((0.04f * vi) + 5) * vi) + 140 - ui + ici);
						ui += c1 * ai * ((bi * vi) - ui);
						vi = vi2;
						if (dumpState)
						{
							const NeuronId n = static_cast<NeuronId>(i);
							if (n >= Ne)
							{
								dumperState.store(static_cast<NeuronId>(i), currentTimeInMs, static_cast<int>(j), vi, ui, ici);
							}
						}

						//////////////////////////////////////////
						// handle update state after spiking
						const bool mi = (vi > threshold_i); // c = (a > b) 
						if (mi)
						{
							vi = ci; // voltage reset
							ui += di * nSubMs; // u += d;	// recovery variable reset

							//if (sti != static_cast<int>(0xFFFFFFFF)) printf("spike::v4::Network4::updateState_X64: Warning: neuron %zu spikes at subMs %zu, ignoring the privious spike at subMs %u\n", i, j, sti);
							sti = static_cast<int>(j);
						}
						else
						{
							if (checkForFutureSpikes)
							{
								const float icif = 0;

								float vif = vi;
								float uif = ui;

								for (size_t jf = 1; jf < (nMsFutureCheck*nSubMs); ++jf)
								{

									float vi2f = vif;
									vi2f += c1 * ((((0.04f * vif) + 5) * vif) + 140 - uif + icif);
									uif += c1 * ai * ((bi * vif) - uif);
									vif = vi2f;

									if (vif > threshold_i)
									{

										vi = ci; // voltage reset
										ui += di * nSubMs; // u += d;	// recovery variable reset
										sti = static_cast<int>(j);

										//printf("spike::v4::Network4::updateState_X64: Info: neuron %u spikes in the future in %f ms; jf=%zu\n", i, static_cast<float>(jf) / nSubMs, jf);
										break;
									}
								}
							}
						}
					}

					st[i] = sti;
					u[i] = ui;
					v[i] = vi;
				}
			}

			template <bool dumpState>
			static inline void updateState_X64_Original(
				float v[N],
				float u[N],
				int st[N],	// spikeTimeInSubMs
				const int timeInMs, // only needed for dumping
				const float ic[N * nSubMs],
				const float a[N],
				const float b[N],
				const float c[N],
				const float d[N],
				DumperState4<nNeurons, nSubMs>& dumperState)
			{
				static_assert(nSubMs == 1, "nSubMs has to be equal to 1");

				const float threshold_i = 30;

				for (size_t i = 0; i < nNeurons; ++i)
				{

					float vi = v[i];
					float ui = u[i];
					const float ici = ic[i];

					BOOST_ASSERT_MSG_HJ(std::isfinite(u[i]), "u[" << i << "] is " << ui);
					BOOST_ASSERT_MSG_HJ(std::isfinite(v[i]), "v[" << i << "] is " << vi);
					BOOST_ASSERT_MSG_HJ(std::isfinite(ic[i]), "ic[" << i << "] is " << ici);

					const float tt = 140 - ui + ici;
					vi += 0.5f * ((((0.04f * vi) + 5) * vi) + tt); // for numerical stability
					vi += 0.5f * ((((0.04f * vi) + 5) * vi) + tt); // time step is 0.5 ms
					ui += a[i] * ((b[i] * vi) - ui);

					//////////////////////////////////////////
					// handle update state after spiking
					int sti = static_cast<int>(0xFFFFFFFF);
					if (vi > threshold_i)
					{
						vi = c[i]; // voltage reset
						ui += d[i];	// u += d;	// recovery variable reset
						sti = 0;
					}

					v[i] = vi;
					u[i] = ui;
					st[i] = sti;
				}
			}
		};
	}
}