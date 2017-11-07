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

#include <vector>
#include <math.h>

#include "../../Spike-Tools-LIB/SpikeTypes.hpp"
#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"


namespace spike
{
	namespace v4
	{
		using namespace spike::v1;

		template <typename Topology>
		class Synapses4
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
			Synapses4()
				: w_(std::vector<float>(nNeurons*nNeurons, std::numeric_limits<float>::quiet_NaN()))
				, wd_plus_(std::vector<float>(nNeurons*nNeurons, 0))
				, wd_min_(std::vector<float>(nNeurons*nNeurons, 0))

				, outgoingNeurons_(nNeurons, std::vector<std::vector<NeuronId>>(D, std::vector<NeuronId>()))
				, incommingNeurons_(nNeurons, std::vector<NeuronId>())
			{
			}


			void incWeight(const float delta)
			{
				for (size_t i = 0; i < this->w_.size(); ++i)
				{
					this->w_[i] += delta;
				}
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

			float getWeightDelta(const NeuronId origin, const NeuronId destination) const
			{
				this->check(origin, destination);
				const size_t i = this->index(origin, destination);
				return this->wd_plus_[i] - this->wd_min_[i];
			}

			std::array<float, 2> getWeightDeltaPlusMin(const NeuronId origin, const NeuronId destination) const
			{
				this->check(origin, destination);
				const size_t i = this->index(origin, destination);
				return{ this->wd_plus_[i], this->wd_min_[i] };
			}

			void incWeightDelta(const NeuronId origin, const NeuronId destination, const float wD)
			{
				//if (origin == 0) std::cout << "incWeightDelta: origin=" << origin << "; destination=" << destination << "; wD=" << wD << std::endl;
				if (wD != 0)
				{
					::tools::assert::assert_msg(wD >= 0, "decWeightDelta: wD=", wD, " has to be larger than zero");
					//if (Topology::isMotorNeuron(origin) || Topology::isMotorNeuron(destination)) std::cout << "incWeightDelta: " << origin << "->" << destination << ": " << value << std::endl;
					this->check(origin, destination);
					this->wd_plus_[this->index(origin, destination)] += wD;
				}
			}

			void decWeightDelta(const NeuronId origin, const NeuronId destination, const float wD)
			{
				//if (origin == 0) std::cout << "decWeightDelta: origin=" << origin << "; destination=" << destination << "; wD=" << wD << std::endl;
				if (wD != 0)
				{
					::tools::assert::assert_msg(wD <= 0, "decWeightDelta: wD=", wD, " has to be smaller than zero");
					//if (Topology::isMotorNeuron(origin) || Topology::isMotorNeuron(destination)) std::cout << "incWeightDelta: " << origin << "->" << destination << ": " << value << std::endl;
					this->check(origin, destination);
					this->wd_min_[this->index(origin, destination)] -= wD;
				}
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

			const std::vector<NeuronId>& getDestinations(const NeuronId origin, const Delay d) const
			{
				return this->outgoingNeurons_[origin][d];
			}

			const std::vector<NeuronId>& getOrigins(const NeuronId destination) const
			{
				return this->incommingNeurons_[destination];
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
			}

		private:

			std::vector<float> w_;
			std::vector<float> wd_plus_;
			std::vector<float> wd_min_;

			std::vector<std::vector<std::vector<NeuronId>>> outgoingNeurons_;
			std::vector<std::vector<NeuronId>> incommingNeurons_;

			size_t index(const NeuronId origin, const NeuronId destination) const
			{
				return (origin * nNeurons) + destination;
			}

			void check(const NeuronId origin, const NeuronId destination) const
			{
				if (std::isnan(this->w_[this->index(origin, destination)]))
				{
					//DEBUG_BREAK();
				}
				::tools::assert::assert_msg(!std::isnan(this->w_[this->index(origin, destination)]), "position not initialized: origin=", origin, "; destination=", destination);
			}
		};
	}
}