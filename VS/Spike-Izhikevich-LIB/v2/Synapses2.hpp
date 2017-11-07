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
#include <memory>

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"

namespace spike
{
	namespace v2
	{
		using namespace spike::v1;

		template <typename Topology>
		class Synapses2
		{
		public:

			static const size_t Ne = Topology::Ne;
			static const size_t Ni = Topology::Ni;
			static const size_t Ns = Topology::Ns;
			static const size_t Nm = Topology::Nm;
			static const size_t nNeurons = Topology::nNeurons;

			//static const SynapseLength M = Topology::M;
			static const Delay D = Topology::D;

			// constructor
			Synapses2()
				: w_(std::vector<float>(nNeurons*nNeurons, std::numeric_limits<float>::quiet_NaN()))
				, wd_plus_(std::vector<unsigned int>(nNeurons*nNeurons, 0))
				, wd_min_(std::vector<unsigned int>(nNeurons*nNeurons, 0))
				, lastDeliverTime_(std::vector<int>(nNeurons*nNeurons, -1000))

				, outgoingNeurons_(nNeurons, std::vector<std::vector<NeuronId>>(D, std::vector<NeuronId>()))
				, incommingNeurons_(nNeurons, std::vector<NeuronId>())
			{
				for (size_t i = 0; i < this->incommingSpikes_.size(); ++i)
				{
					this->incommingSpikes_[i] = std::make_shared<std::vector<std::tuple<NeuronId, NeuronId>>>(40000);
				}
				this->nIncommingSpikes_.fill(0);
			}

			float getWeight(const NeuronId origin, const NeuronId destination) const
			{
				//std::cout << "getWeight: origin = " << origin << "; destination = " << destination << "; w(o,d)=" << this->w_[this->index(origin, destination)] << "; w(d,o)=" << this->w_[this->index(destination, origin)] << std::endl;
				this->check(origin, destination);
				return this->w_[this->index(origin, destination)];
			}

			void setWeight(const NeuronId origin, const NeuronId destination, const float value)
			{
				this->w_[this->index(origin, destination)] = value;
			}

			int getWeightDelta(const NeuronId origin, const NeuronId destination) const
			{
				this->check(origin, destination);
				const size_t i = this->index(origin, destination);
				return this->wd_plus_[i] - this->wd_min_[i];
			}

			std::array<unsigned int, 2> getWeightDeltaPlusMin(const NeuronId origin, const NeuronId destination) const
			{
				this->check(origin, destination);
				const size_t i = this->index(origin, destination);
				return{ this->wd_plus_[i], this->wd_min_[i] };
			}

			void incWeightDelta(const NeuronId origin, const NeuronId destination, const unsigned int wD)
			{
				//if (Topology::isMotorNeuron(origin) || Topology::isMotorNeuron(destination)) std::cout << "incWeightDelta: " << origin << "->" << destination << ": " << value << std::endl;
				this->check(origin, destination);
				this->wd_plus_[this->index(origin, destination)] += wD;
			}

			void decWeightDelta(const NeuronId origin, const NeuronId destination, const unsigned int wD)
			{
				//if (Topology::isMotorNeuron(origin) || Topology::isMotorNeuron(destination)) std::cout << "incWeightDelta: " << origin << "->" << destination << ": " << value << std::endl;
				this->check(origin, destination);
				this->wd_min_[this->index(origin, destination)] += wD;
			}

			void clearWeightDelta()
			{
				for (size_t i = 0; i < nNeurons*nNeurons; ++i)
				{
					this->wd_plus_[i] = 0;
				}
				for (size_t i = 0; i < nNeurons*nNeurons; ++i)
				{
					this->wd_min_[i] = 0;
				}
			}

			int getLastDeliverTimeInMs(const NeuronId origin, const NeuronId destination) const
			{
				return this->lastDeliverTime_[this->index(origin, destination)];
			}

			void setLastDeliverTimeInMs(const NeuronId origin, const NeuronId destination, const unsigned int t)
			{
				this->check(origin, destination);
				const size_t i = this->index(origin, destination);
				this->lastDeliverTime_[i] = static_cast<int>(t);
				const unsigned int nIncommingSpikes = this->nIncommingSpikes_[t];
				this->nIncommingSpikes_[t]++;
				(*this->incommingSpikes_[t])[nIncommingSpikes] = std::make_tuple(origin, destination);
			}

			const std::vector<NeuronId>& getDestinations(const NeuronId origin, const Delay d) const
			{
				return this->outgoingNeurons_[origin][d];
			}

			const std::vector<NeuronId>& getOrigins(const NeuronId destination) const
			{
				return this->incommingNeurons_[destination];
			}

			std::tuple<unsigned int, const std::shared_ptr<const std::vector<std::tuple<NeuronId, NeuronId>>>> getIncommingSpikes(const unsigned int t) const
			{
				return std::make_tuple(this->nIncommingSpikes_[t], this->incommingSpikes_[t]);
			}

			void init(const std::shared_ptr<Topology>& topology)
			{
				// copy the pathways from topology to this network
				for (const NeuronId neuronId : Topology::iterator_AllNeurons())
				{

					const std::vector<Pathway>& outgoingPathways = topology->getOutgoingPathways(neuronId);
					const std::vector<Pathway>& incommingPathways = topology->getIncommingPathways(neuronId);

					for (Delay d = 0; d < D; ++d)
					{

						std::vector<NeuronId>& outgoingNeurons = this->outgoingNeurons_[neuronId][d];
						std::vector<NeuronId>& incommingNeurons = this->incommingNeurons_[neuronId];

						outgoingNeurons.clear();

						for (const Pathway& p : outgoingPathways)
						{
							if (p.delay == d)
							{
								::tools::assert::assert_msg(p.origin == neuronId, "incorrect origin");
								outgoingNeurons.push_back(p.destination);
								this->setWeight(neuronId, p.destination, p.weight);
							}
						}

						incommingNeurons.clear();
						for (const Pathway& p : incommingPathways)
						{
							::tools::assert::assert_msg(p.destination == neuronId, "incorrect destination");
							incommingNeurons.push_back(p.origin);
						}
					}
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
				size_t count = 0;
				for (Delay d = 0; d < D; ++d)
				{
					for (const NeuronId destination : this->getDestinations(neuronId, d))
					{
						sum += this->getWeight(neuronId, destination);
						count++;
					}
				}
				return static_cast<float>(sum / count);
			}

			float getAverageIncommingWeight(const NeuronId neuronId) const
			{
				double sum = 0;
				size_t count = 0;
				for (const NeuronId origin : this->getOrigins(neuronId))
				{
					sum += this->getWeight(origin, neuronId);
					count++;
				}
				return static_cast<float>(sum / count);
			}

			float getAverageIncommingWeightMotor() const
			{
				double sum = 0;
				unsigned int counter = 0;
				for (const NeuronId& neuronId : Topology::iterator_MotorNeurons())
				{
					const float averageWeight = this->getAverageIncommingWeight(neuronId);
					//std::cout << "Spike_Network_State::getAverageOutgoingWeightSensor: neuronId=" << neuronId << "; average weight " << averageWeight << std::endl;
					sum += averageWeight;
					counter++;
				}
				return static_cast<float>((counter == 0) ? 0 : (sum / counter));
			}


			void resetSecond()
			{
				//std::cout << "resetSecond" << std::endl;
				for (size_t i = 0; i < this->incommingNeurons_.size(); ++i)
				{
					const NeuronId destination = static_cast<NeuronId>(i);
					for (const NeuronId& origin : this->incommingNeurons_[i])
					{
						this->lastDeliverTime_[this->index(origin, destination)] -= 1000;
					}
				}
				for (Delay d = 0; d < D; ++d)
				{
					swap(this->incommingSpikes_[d], this->incommingSpikes_[d + 1000]);
					this->nIncommingSpikes_[d] = this->nIncommingSpikes_[d + 1000];
				}
				for (size_t i = D; i < 1000 + D; ++i)
				{
					this->nIncommingSpikes_[i] = 0;
				}
			}

		private:
			std::vector<float> w_;
			std::vector<unsigned int> wd_plus_;
			std::vector<unsigned int> wd_min_;
			std::vector<int> lastDeliverTime_;

			std::vector<std::vector<std::vector<NeuronId>>> outgoingNeurons_;
			std::vector<std::vector<NeuronId>> incommingNeurons_;

			std::array<std::shared_ptr<std::vector<std::tuple<NeuronId, NeuronId>>>, 1000 + D> incommingSpikes_;
			std::array<unsigned int, 1000 + D> nIncommingSpikes_;

			size_t index(const NeuronId origin, const NeuronId destination) const
			{
				return (origin * nNeurons) + destination;
			}

			void check(const NeuronId origin, const NeuronId destination) const
			{
				::tools::assert::assert_msg(!std::isnan(this->w_[this->index(origin, destination)]), "position not initialized: origin=", origin, "; destination=", destination);
			}
		};
	}
}