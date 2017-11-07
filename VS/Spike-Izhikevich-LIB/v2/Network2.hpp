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
#include <chrono>

#include "../../Spike-Tools-LIB/DumperSpikes.hpp"
#include "../../Spike-Tools-LIB/DumperTopology.hpp"
#include "../../Spike-Tools-LIB/SpikeTypes.hpp"

#include "../../Spike-Izhikevich-LIB/DumperState.hpp"
#include "../../Spike-Izhikevich-LIB/DumperWeigthDelta.hpp"
#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"
#include "../../Spike-Izhikevich-LIB/Topology.hpp"

#include "../../Spike-Izhikevich-LIB/v2/InputCurrent2.hpp"
#include "../../Spike-Izhikevich-LIB/v2/Synapses2.hpp"


namespace spike
{
	namespace v2
	{
		using namespace ::spike::tools;
		using namespace ::spike::dataset;

		template <typename Topology_i>
		class Network2
		{
		public:
			using TimePoint = std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration>;

			using Topology = Topology_i;
			//using Options = Topology_i::Options;

			static const size_t Ne = Topology::Ne;
			static const size_t Ni = Topology::Ni;
			static const size_t Ns = Topology::Ns;
			static const size_t Nm = Topology::Nm;
			static const size_t nNeurons = Topology::nNeurons;
			static const size_t N = Topology::N;

			static const size_t D = Topology::D;
			static const size_t M = Topology::M;

			static constexpr float tau_p = 10.0f;
			static constexpr float tau_m = 4.0f;
			static constexpr float tau_star_p = 120.0f / (tau_p * tau_p);
			static constexpr float tau_star_m = 200.0f / (tau_m * tau_m);


			// constructor
			Network2() = delete;

			// constructor
			Network2(const SpikeRuntimeOptions& spikeRuntimeOptions)
				: dumperSpikes_(DumperSpikes<Ms>(spikeRuntimeOptions))
				, dumperState_(DumperState<nNeurons>(spikeRuntimeOptions))
				, dumperTopology_(DumperTopology<Topology>(spikeRuntimeOptions))
				, dumperWeightDelta_(DumperWeightDelta(spikeRuntimeOptions))
			{
				for (size_t i = 0; i < N; ++i)
				{
					this->lastSpikeTime_[i] = -1000;
				}

				std::cout << "Network2 constructor: tau_p=" << tau_p << "; tau_m=" << tau_m << "; tau_star_p=" << tau_star_p << "; tau_star_m=" << tau_star_m << std::endl;
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

			void train(const unsigned int nSeconds, const bool useConfusionMatrix, const bool plotProgress)
			{
				this->spikeStream_->start();
				this->startTime_ = std::chrono::system_clock::now();

				for (unsigned int sec = 0; sec < nSeconds; ++sec)
				{
					const bool dumpSpikes = this->dumperSpikes_.dumpTest(sec);
					const bool dumpState = this->dumperState_.dumpTest(sec);
					const bool dumpWeightDelta = this->dumperWeightDelta_.dumpTest(sec);

					if (dumpSpikes)
					{
						this->spikeStream_->clearCaseUsage();
						this->spikeData_.clear();
					}

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

					this->resetSecond();

					if (this->dumperTopology_.dumpTest(sec)) this->dumperTopology_.dump(sec, "newCode", this->getTopology());
					if (dumpSpikes) this->dumperSpikes_.dump(sec, "newCode", this->spikeData_, this->spikeStream_->getCaseUsage());
					if (dumpState) this->dumperState_.dump(sec, "newCode");
					if (dumpWeightDelta) this->dumperWeightDelta_.dump(sec, "newCode");
				}
			}

			void stateOverviewForMatlab(const std::string& filename)
			{
				// parameters
				const NeuronId neuronId = 0;

				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "DataSetBackendTxt::saveToFileBackend(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				// try to open file
				std::ofstream outputFile(filename); //fstream is a proper RAII object, it does close automatically at the end of the scope
				if (!outputFile.is_open())
				{
					std::cerr << "Topology::saveToFile(): Unable to open file " << filename << std::endl;
					throw std::runtime_error("Unable to open file");
				}
				else
				{
					outputFile << "v\tu\tI" << std::endl;

					//1] make sure voltages are at rest state;
					for (unsigned int t = 0; t < 100; ++t)
					{
						this->updateState(t);
					}

					for (unsigned int t = 0; t < 100; ++t)
					{

						if (t == 5) this->ic_.add(neuronId, 1, t, 10);
						if (t == 10) this->ic_.add(neuronId, 1, t, 10);
						if (t == 15) this->ic_.add(neuronId, 1, t, 10);
						if (t == 20) this->ic_.add(neuronId, 1, t, 10);
						if (t == 25) this->ic_.add(neuronId, 1, t, 10);


						if (t == 40) this->ic_.add(neuronId, 1, t, 10);
						if (t == 41) this->ic_.add(neuronId, 1, t, 10);

						if (t == 60) this->ic_.add(neuronId, 1, t, 10);
						if (t == 61) this->ic_.add(neuronId, 1, t, 10);

						if (this->v_[neuronId] >= spike::v1::constant::firingThreshold)
						{
							this->v_[neuronId] = this->c_[neuronId];	// voltage reset
							this->u_[neuronId] += this->d_[neuronId];	// recovery variable reset
						}
						this->updateState(t);

						outputFile << this->v_[neuronId] << "\t" << this->u_[neuronId] << "\t" << this->ic_.getPtr(t)[neuronId] << std::endl;
					}
				}
			}

		private:

			std::shared_ptr<Topology> topology_;

			Synapses2<Topology> synapses_;
			InputCurrent2<nNeurons, D> ic_;

			int __declspec(align(4)) lastSpikeTime_[N];

			float __declspec(align(4)) is_[N];
			float __declspec(align(4)) trainRate_[N];

			float __declspec(align(4)) v_[N];
			float __declspec(align(4)) u_[N];

			float __declspec(align(4)) a_[N];
			float __declspec(align(4)) b_[N];
			float __declspec(align(4)) c_[N];
			float __declspec(align(4)) d_[N];


			TimePoint startTime_;

			SpikeSet1Sec<Ms> spikeData_;
			SpikeNetworkPerformance<Topology, Ms> spikeNetworkPerformance_;
			std::shared_ptr<SpikeStream<Topology>> spikeStream_;

			DumperSpikes<Ms> dumperSpikes_;
			spike::v1::DumperState<nNeurons> dumperState_;
			DumperTopology<Topology> dumperTopology_;
			spike::v1::DumperWeightDelta dumperWeightDelta_;



			template <bool dumpWeightDelta>
			void ltd(const unsigned int t)
			{
				//for all the incomming spikes at time t
				const auto results = this->synapses_.getIncommingSpikes(t);
				const unsigned int nIncommingSpikes = std::get<0>(results);
				const std::shared_ptr<const std::vector<std::tuple<NeuronId, NeuronId>>> incommingSpikesPtr = std::get<1>(results);

				for (unsigned int i = 0; i < nIncommingSpikes; ++i)
				{
					const std::tuple<NeuronId, NeuronId> path = (*incommingSpikesPtr)[i];
					const NeuronId origin = std::get<0>(path);
					const NeuronId destination = std::get<1>(path);

					// get the time that this destination neuron has spiked
					const int spikeTime = this->lastSpikeTime_[destination];
					// the time this destination neuron spiked can only be in the past (smaller than t)
					::tools::assert::assert_msg(spikeTime <= static_cast<int>(t), "LTD: t=", t, "; spikeTime=", spikeTime);

					const unsigned short wD = this->calcWeightDeltaLtd(spikeTime, t);
					if (wD > 0)
					{
						//if (Topology::isMotorNeuron(destination) && (wD != 0)) std::cout << "LTD:  t=" << t << ": neuron " << origin << " spiked at " << this->lastSpikeTime_[origin] << " and contributes at " << t << " to neuron " << destination << "; Neuron " << destination << " last spiked at " << spikeTime << "; wD=" << wD << std::endl;
						this->synapses_.decWeightDelta(origin, destination, wD);
						if (dumpWeightDelta) this->dumperWeightDelta_.store_WeightDelta(t, origin, destination, -wD);
					}
				}
			}

			void resetSecond()
			{
				this->ic_.resetTime();

				// substract 1 second from the last spike times
				for (const NeuronId neuronId : Topology::iterator_AllNeurons())
				{
					this->lastSpikeTime_[neuronId] -= 1000;
				}
			}

			void addToSpikeData(const Ms t, const NeuronId neuronId, const FiringReason firingReason)
			{
				this->spikeData_.addFiring(t, neuronId, firingReason);
			}

			template <bool dumpSpikes, bool dumpState, bool dumpWeightDelta>
			void run1Second(const unsigned int sec, const unsigned int nSeconds, const bool useConfusionMatrix, const bool plotProgress)
			{
				for (unsigned int t = 0; t < 1000; ++t)
				{

					if (dumpState) this->dumperState_.store_State(static_cast<Ms>(t), this->v_, this->u_, this->ic_.getPtr(t));

					//1] start a new case if needed
					this->spikeStream_->startNewCaseIfNeeded();
					//2] handle firing neurons 
					this->handleFiringNeurons<dumpSpikes, dumpWeightDelta>(t);
					//4] calculate the new potential
					this->updateState(t);
					//5] calculate the new STDP values for ltd
					this->ltd<dumpWeightDelta>(t);
					//6] increment time in the stream
					this->spikeStream_->incTime();
				}
				this->updateWeight(sec);
				this->synapses_.resetSecond();

				if (plotProgress)
				{
					this->plotProgressInfo(this->startTime_, sec, nSeconds);
				}
				if (useConfusionMatrix)
				{
					if (((sec % (10 * 60)) == 0) && (sec > 0))
					{
						std::cout << this->spikeNetworkPerformance_.toStringConfusionMatrix() << std::endl;
						//std::cout << this->spikeNetworkPerformance_.toStringPerformance() << std::endl;
						std::cout << "avg precision " << this->spikeNetworkPerformance_.getAveragePrecision() << std::endl;
						this->spikeNetworkPerformance_.clear();
					}
				}
			}

			void plotProgressInfo(TimePoint& startTime, const unsigned int sec, const unsigned int totalSeconds) const
			{
				if ((sec % (1 * 60) == 0) && (sec > 0))
				{
					const TimePoint timeNow = std::chrono::system_clock::now();
					const auto diff = timeNow - startTime;
					startTime = timeNow;

					const float avgWeightOutSensor = this->synapses_.getAverageOutgoingWeightSensor();
					const float avgWeightOutExcitatory = this->synapses_.getAverageOutgoingWeightExcitatory();
					const float avgWeightInMotor = this->synapses_.getAverageIncommingWeightMotor();

					const float avgFiringRate = (static_cast<float>(this->spikeData_.nFirings_) / nNeurons);

					std::cout << "sec " << sec << "/" << totalSeconds << ";\ttime for 1 min: " << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() << " ms;\tfiring rate " << avgFiringRate << " hz;\tavg-w-out-exc=" << avgWeightOutExcitatory << ";\tavg-w-out-sensor=" << avgWeightOutSensor << ";\tavg-w-in-motor=" << avgWeightInMotor << std::endl;
				}
			}

			template <bool dumpSpikes, bool dumpWeightDelta>
			void handleFiringNeurons(const unsigned int t)
			{
				//::tools::assert::assert_msg(t >= 0, "handleFiringNeurons_train:: provided t is too small. t=", t);
				::tools::assert::assert_msg(t < 1000, "handleFiringNeurons_train:: provided t is too large.t = ", t);

				for (const NeuronId& neuronId : Topology::iterator_AllNeurons())
				{

					const FiringReason firingReason = this->isNeuronFired(neuronId);

					if (firingReason != FiringReason::NO_FIRE)
					{

						/*
						if (Topology::isMotorNeuron(neuronId)) {
						if (firingReason == FiringReason::FIRE_PROPAGATED_CORRECT) {
						std::cout << "isNeuronFired: t=" << t << ": motor neuron " << neuronId << " fires a correct spike!!" << std::endl;
						} else if (firingReason == FiringReason::FIRE_PROPAGATED_INCORRECT) {
						std::cout << "isNeuronFired: t=" << t << ": motor neuron " << neuronId << " fires an correct spike!!" << std::endl;
						}
						}
						*/
						//1] update state
						this->v_[neuronId] = this->c_[neuronId];	// voltage reset
						this->u_[neuronId] += this->d_[neuronId];	// recovery variable reset

						//2] update last fire time of firing neuron
						this->lastSpikeTime_[neuronId] = static_cast<int>(t);

						//3] update the input current
						const NeuronId origin = neuronId;
						for (Delay d = 0; d < static_cast<Delay>(D); ++d)
						{
							for (const NeuronId& destination : this->synapses_.getDestinations(origin, d))
							{
								//1: update input current of the neuron that receives this spike
								//std::cout << "fire: firingNeuronId=" << firingNeuronId << "; receivingNeuronId=" << receivingNeuronId << std::endl;
								this->ic_.add(destination, d, t, this->synapses_.getWeight(origin, destination));

								//2: for LTD: store at what time a spike is received at destination
								//3: set the last deliver time of this spike to the receiving neuron
								this->synapses_.setLastDeliverTimeInMs(origin, destination, t + d);
							}
						}

						//4] LTP: find all the synapses that contributed to the firing of firingNeuronId, award the spikes that contributed most recently

						for (const NeuronId& contributingNeuronId : this->synapses_.getOrigins(neuronId))
						{
							const int contributionTime = this->synapses_.getLastDeliverTimeInMs(contributingNeuronId, neuronId);
							if (contributionTime < static_cast<int>(t))
							{
								const unsigned short wD = this->calcWeightDeltaLtp(contributionTime, t);
								if (wD > 0)
								{
									//if (Topology::isMotorNeuron(neuronId) && (wD!=0)) std::cout << "fire: t=" << t << ": neuron " << neuronId << " fires at " << t << "; neuron " << contributingNeuronId << " contributed at time " << contributionTime << "; wD=" << wD << std::endl;

									if (firingReason == FiringReason::FIRE_PROPAGATED_INCORRECT)
									{
										this->synapses_.decWeightDelta(contributingNeuronId, neuronId, wD);
										if (dumpWeightDelta) this->dumperWeightDelta_.store_WeightDelta(t, contributingNeuronId, neuronId, -wD);
									}
									else if (firingReason == FiringReason::FIRE_PROPAGATED_CORRECT)
									{
										this->synapses_.incWeightDelta(contributingNeuronId, neuronId, 100 * wD);
										if (dumpWeightDelta) this->dumperWeightDelta_.store_WeightDelta(t, contributingNeuronId, neuronId, 100 * wD);
									}
									else
									{
										this->synapses_.incWeightDelta(contributingNeuronId, neuronId, wD);
										if (dumpWeightDelta) this->dumperWeightDelta_.store_WeightDelta(t, contributingNeuronId, neuronId, wD);
									}
								}
							}
						}
						if (dumpSpikes) this->addToSpikeData(static_cast<Ms>(t), neuronId, firingReason);
					}
				}
			}

			FiringReason isNeuronFired(const NeuronId neuronId)
			{
				FiringReason result;
				if (Topology::isSensorNeuron(neuronId))
				{
					const bool neuronClampedValue = this->spikeStream_->getClampedValue(neuronId);
					if (neuronClampedValue)
					{
						//std::cout << "isNeuronFired: sensor neuron " << neuronId << "; going to return FIRE_CLAMPED" << std::endl;
						result = FiringReason::FIRE_CLAMPED;
					}
					else
					{
						if (this->spikeStream_->hasRandomSpike(neuronId))
						{
							result = FiringReason::FIRE_RANDOM;
						}
						else
						{
							result = FiringReason::NO_FIRE;
						}
					}
				}
				else if (Topology::isMotorNeuron(neuronId))
				{

					const CaseLabel correctLabel = this->spikeStream_->getCurrentLabel();
					const CaseLabel observedLabel = CaseLabel(static_cast<CaseLabelType>(neuronId - (Ni + Ne))); // TODO heck;

					const bool neuronCanFire = (this->v_[neuronId] >= spike::v1::constant::firingThreshold);
					if (neuronCanFire)
					{
						if (correctLabel == NO_CASE_LABEL)
						{
							result = FiringReason::FIRE_PROPAGATED;
						}
						else
						{
							if (observedLabel == correctLabel)
							{
								//std::cout << "isNeuronFired: motor neuron " << neuronId << "; correctLabel=" << correctLabel << "; going to return FIRE_PROPAGATED_CORRECT" << std::endl;
								result = FiringReason::FIRE_PROPAGATED_CORRECT;
							}
							else
							{
								//std::cout << "isNeuronFired: motor neuron " << neuronId << "; correctLabel=" << correctLabel << "; going to return FIRE_PROPAGATED_INCORRECT" << std::endl;
								result = FiringReason::FIRE_PROPAGATED_INCORRECT;
							}
							this->spikeNetworkPerformance_.addEvent2(observedLabel, correctLabel, result);
						}
					}
					else
					{
						if (this->spikeStream_->hasRandomSpike(neuronId))
						{
							result = FiringReason::FIRE_RANDOM;
							if (correctLabel != NO_CASE_LABEL)
							{
								this->spikeNetworkPerformance_.addEvent2(observedLabel, correctLabel, result);
							}
						}
						else
						{
							result = FiringReason::NO_FIRE;
						}
					}
				}
				else
				{
					const bool neuronCanFire = (this->v_[neuronId] >= spike::v1::constant::firingThreshold);
					if (neuronCanFire)
					{
						result = FiringReason::FIRE_PROPAGATED;
					}
					else
					{
						if (this->spikeStream_->hasRandomSpike(neuronId))
						{
							result = FiringReason::FIRE_RANDOM;
						}
						else
						{
							result = FiringReason::NO_FIRE;
						}
					}
				}
				return result;
			}

			unsigned short calcWeightDeltaLtp(const int contributionTime, const unsigned int fireTime) const
			{
				::tools::assert::assert_msg(contributionTime < static_cast<int>(fireTime), "calcWeightDeltaLtp: contributionTime=", contributionTime, " has to be before fireTime=", fireTime);
				const int relativeDeliverTime = static_cast<int>(fireTime) - contributionTime;
				::tools::assert::assert_msg(relativeDeliverTime > 0, "calcWeightDeltaLtp: relativeDeliverTime=", relativeDeliverTime, " has to be larger than zero");

				if (relativeDeliverTime < tau_p)
				{
					const int result = static_cast<int>(this->tau_star_p * ((tau_p - relativeDeliverTime + 1) * (tau_p - relativeDeliverTime + 1)));
					//std::cout << "calcWeightDeltaLtp: return " << result << "; relativeDeliverTime=" << relativeDeliverTime << "; tau_star_p=" << tau_star_p << "; contributionTime=" << contributionTime << "; fireTime=" << fireTime << std::endl;
					return static_cast<unsigned short>(result);
				}
				else
				{
					return 0;
				}
			}

			unsigned short calcWeightDeltaLtd(const int spikeTime, const unsigned int t) const
			{
				::tools::assert::assert_msg(spikeTime <= static_cast<int>(t), "calcWeightDeltaLtd: spikeTime=", spikeTime, " has to be after (or equal to) current time=", t);
				const int relativeDeliverTime = spikeTime - static_cast<int>(t);
				::tools::assert::assert_msg(relativeDeliverTime <= 0, "calcWeightDeltaLtd: relativeDeliverTime=", relativeDeliverTime, " has to be smaller (or equal to) zero. spikeTime=", spikeTime, "; t=", t);

				//std::cout << "calcWeightDeltaLtd: relativeDeliverTime=" << relativeDeliverTime << "; spikeTime=" << spikeTime << "; t=" << t << std::endl;
				if (relativeDeliverTime > -tau_m)
				{
					const int result = static_cast<int>(this->tau_star_m * ((relativeDeliverTime + tau_m) * (relativeDeliverTime + tau_m)));
					//std::cout << "calcWeightDeltaLtd: return " << result << "; relativeDeliverTime=" << relativeDeliverTime << "; tau_star_m=" << tau_star_m << "; spikeTime=" << spikeTime << "; t=" << t << std::endl;
					return static_cast<unsigned short>(result);
				}
				else
				{
					return 0;
				}
			}

			void incWeight(const NeuronId origin, const NeuronId destination, const float delta)
			{
				float weightInc = (delta * 0.0001f);

				//std::cout << "incWeight: weightInc=" << weightInc << "; oldWeight = " << oldWeight << "; delta = " << delta << std::endl;
				if (weightInc > 1.0f)
				{
					weightInc = 1.0f;
					//std::cout << "incWeight: weightInc=" << weightInc<< "; delta = " << delta << "; average = " << average << std::endl;
				}
				else if (weightInc < -1.0f)
				{
					weightInc = -1.0f;
					//std::cout << "incWeight: weightInc=" << weightInc << "; delta = " << delta << "; average = " << average << std::endl;
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

			std::array<double, 2> getAverageWeightDeltaPlusMin() const
			{
				unsigned int sum_plus = 0;
				unsigned int sum_min = 0;
				unsigned int count = 0;

				for (const NeuronId& destination : Topology::iterator_AllNeurons())
				{
					for (const NeuronId& origin : this->synapses_.getOrigins(destination))
					{
						if (!Topology::isInhibitoryNeuron(origin))
						{
							const std::array<unsigned int, 2> deltaPlusMin = this->synapses_.getWeightDeltaPlusMin(origin, destination);
							sum_plus += deltaPlusMin[0];
							sum_min += deltaPlusMin[1];
							count++;
						}
					}
				}
				const double averagePlus = (count > 0) ? (static_cast<double>(sum_plus) / count) : 0;
				const double averageMin = (count > 0) ? (static_cast<double>(sum_min) / count) : 0;
				return{ averagePlus, averageMin };
			}

			void updateWeight(const unsigned int sec)
			{
				const bool useWeightChangeBalancing = true;
				if (useWeightChangeBalancing)
				{
					const std::array<double, 2> averageWeightDeltaPlusMin = this->getAverageWeightDeltaPlusMin();
					const double balance = averageWeightDeltaPlusMin[0] / averageWeightDeltaPlusMin[1];

					//if ((sec % (1 * 1) == 0) && (sec > 0)) {
					//	std::cout << "updateWeight: sec=" << sec << "; average averagePlus=" << averageWeightDeltaPlusMin[0] << "; average averageMin=" << averageWeightDeltaPlusMin[1] << "; balance=" << balance << std::endl;
					//}

					for (const NeuronId& destination : Topology::iterator_AllNeurons())
					{
						for (const NeuronId& origin : this->synapses_.getOrigins(destination))
						{
							if (!Topology::isInhibitoryNeuron(origin))
							{
								const std::array<unsigned int, 2> deltaArray = this->synapses_.getWeightDeltaPlusMin(origin, destination);
								const double delta = static_cast<double>(deltaArray[0]) - (balance * static_cast<double>(deltaArray[1]));
								this->incWeight(origin, destination, static_cast<float>(delta));
							}
						}
					}
				}
				else
				{
					for (const NeuronId& destination : Topology::iterator_AllNeurons())
					{
						for (const NeuronId& origin : this->synapses_.getOrigins(destination))
						{
							if (!Topology::isInhibitoryNeuron(origin))
							{
								const double delta = static_cast<double>(this->synapses_.getWeightDelta(origin, destination));
								this->incWeight(origin, destination, static_cast<float>(delta));
							}
						}
					}
				}
				this->synapses_.clearWeightDelta();
			}

			void updateState(const unsigned int t)
			{
				updateState_Sse<Ne + Ni + Nm>(this->v_, this->u_, this->ic_.getPtr(t), this->is_, this->a_, this->b_);
				//updateState_X64<Ne + Ni + Nm>(this->v_, this->u_, this->ic_.getPtr(t), this->is_, this->a_, this->b_);
			}

			template <size_t nNeurons2>
			static inline void updateState_Sse(float v[], float u[], const float ic[], const float is[], const float a[], const float b[])
			{
				const __m128 c1 = _mm_set1_ps(0.5f);
				const __m128 c2 = _mm_set1_ps(0.04f);
				const __m128 c3 = _mm_set1_ps(5.0f);
				const __m128 c4 = _mm_set1_ps(140.0f);

				for (size_t i = 0; i < nNeurons2; i += 4)
				{

					const __m128 ici = _mm_load_ps(&ic[i]);
					//const __m128 isi = _mm_load_ps(&is[i]);

					__m128 vi = _mm_load_ps(&v[i]);
					__m128 ui = _mm_load_ps(&u[i]);

					// + 140 - u[i] + (is[i] * ic[i])
					//	const __m128 tt = _mm_add_ps(_mm_sub_ps(_mm_mul_ps(isi, ici), ui), c4);

					// + 140 - u[i] + ic[i]
					const __m128 tt = _mm_add_ps(_mm_sub_ps(ici, ui), c4);

					//////////////////////////////////////////
					//	v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // for numerical stability
					const __m128 x1a = _mm_mul_ps(vi, c2);
					const __m128 x2a = _mm_add_ps(x1a, c3);
					const __m128 x3a = _mm_mul_ps(x2a, vi);
					const __m128 x4a = _mm_add_ps(x3a, tt);
					const __m128 x5a = _mm_mul_ps(x4a, c1);
					vi = _mm_add_ps(x5a, vi);

					//////////////////////////////////////////
					//	v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // time step is 0.5 ms
					const __m128 x1b = _mm_mul_ps(vi, c2);
					const __m128 x2b = _mm_add_ps(x1b, c3);
					const __m128 x3b = _mm_mul_ps(x2b, vi);
					const __m128 x4b = _mm_add_ps(x3b, tt);
					const __m128 x5b = _mm_mul_ps(x4b, c1);
					vi = _mm_add_ps(x5b, vi);

					//////////////////////////////////////////
					//	u[i] += a[i] * ((b[i] * v[i]) - u[i]);
					const __m128 bi = _mm_load_ps(&b[i]);
					const __m128 y1 = _mm_mul_ps(vi, bi);
					const __m128 y2 = _mm_sub_ps(y1, ui);

					const __m128 ai = _mm_load_ps(&a[i]);
					const __m128 y3 = _mm_mul_ps(y2, ai);
					ui = _mm_add_ps(y3, ui);

					_mm_store_ps(&v[i], vi);
					_mm_store_ps(&u[i], ui);
				}
			}

			template <size_t nNeurons>
			static inline void updateState_X64(float v[], float u[], const float ic[], const float is[], const float a[], const float b[])
			{
				for (size_t i = 0; i < nNeurons; ++i)
				{
					BOOST_ASSERT_MSG_HJ(std::isfinite(u[i]), "u[" << i << "] is " << u[i]);
					BOOST_ASSERT_MSG_HJ(std::isfinite(v[i]), "v[" << i << "] is " << v[i]);
					BOOST_ASSERT_MSG_HJ(std::isfinite(ic[i]), "ic[" << i << "] is " << v[i]);

					//				if (!std::isfinite(u[i])) __debugbreak();
					//				if (!std::isfinite(v[i])) __debugbreak();

					//const float tt = 140 - u[i] + (is[i] * ic[i]);
					const float tt = 140 - u[i] + ic[i];

					v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // for numerical stability
					//		if (!std::isfinite(v[i])) __debugbreak();
					v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // time step is 0.5 ms
					//		if (!std::isfinite(v[i])) __debugbreak();

					u[i] += a[i] * ((b[i] * v[i]) - u[i]);
					//if (!std::isfinite(u[i])) __debugbreak();
				}
			}
		};
	}
}