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

namespace spike
{
	namespace v4
	{

		template <size_t nNeurons, size_t nSubMs, size_t maxDelay = 20>
		class Spikes4
		{
		public:

			Spikes4()
				: lastArrivalTime_(std::vector<float>(nNeurons*nNeurons, -1000))
				, lastArrivalTimeCurrent_(std::vector<float>(nNeurons*nNeurons, -1000))
			{
				//std::vector<std::vector<std::vector<std::tuple<NeuronId, int>>>> data_;

				for (size_t d = 0; d < maxDelay; ++d)
				{
					this->data_.push_back(std::vector<std::vector<std::tuple<NeuronId, int>>>());
					for (NeuronId n = 0; n < nNeurons; ++n)
					{
						this->data_[d].push_back(std::vector<std::tuple<NeuronId, int>>());
					}
				}
			}

			void addSpike(const NeuronId origin, const NeuronId destination, const float arrivalTime)
			{
				const float t2 = arrivalTime - this->currentTimeInMs_;
				const size_t d = static_cast<size_t>(t2);
				const size_t subMs = static_cast<size_t>(std::round((t2 - d) * nSubMs));
				size_t i = d + this->current_;
				if (i >= maxDelay) i -= maxDelay;

				::tools::assert::assert_msg(i < maxDelay, "spike::v4::Spikes4: addSpike: origin=", origin, "; destination=", destination, "; arrivalTime=", arrivalTime, "; i=", i, " maxDelay=", maxDelay);


				if ((destination >= nNeurons) || (i >= maxDelay))
				{
					printf("Spikes4::addSpike: origin=%u; destination=%u; arrivalTime=%f; currentTime=%f; i=%zu; subMs=%zu\n", origin, destination, arrivalTime, this->currentTimeInMs_, i, subMs);
				}

				this->data_[i][destination].push_back(std::make_tuple(origin, static_cast<int>(subMs)));
				this->lastArrivalTimeCurrent_[index(origin, destination)] = arrivalTime;
			}

			const std::vector<std::tuple<NeuronId, int>>& getIncommingSpikesCurrentMs(const NeuronId destination) const
			{
				return this->data_[this->current_][destination];
			}

			float getLastArrivalTimeCurrentMs(const NeuronId origin, const NeuronId destination) const
			{
				return this->lastArrivalTime_[this->index(origin, destination)];
			}

			void advance1Ms()
			{
				//std::cout << "spike::v4::Spikes4::advance1Ms" << std::endl;

				for (NeuronId n = 0; n < nNeurons; ++n)
				{
					this->data_[this->current_][n].clear();
				}
				this->currentTimeInMs_++;
				this->current_++;
				if (this->current_ >= static_cast<int>(maxDelay))
				{
					this->current_ = 0;
				}

				memcpy(this->lastArrivalTime_.data(), this->lastArrivalTimeCurrent_.data(), nNeurons* nNeurons * sizeof(float));

			}

			void clear()
			{
				this->current_ = 0;
				this->currentTimeInMs_ = 0;
				for (size_t i = 0; i < maxDelay; ++i)
				{
					for (NeuronId n = 0; n < nNeurons; ++n)
					{
						this->data_[i][n].clear();
					}
				}
			}

			void resetSecond()
			{
				//std::cout << "spike:v4:Spikes4::resetSecond" << std::endl;
				this->currentTimeInMs_ = 0;
			}

		private:

			std::vector<float> lastArrivalTime_;
			std::vector<float> lastArrivalTimeCurrent_;

			std::vector<std::vector<std::vector<std::tuple<NeuronId, int>>>> data_;
			int current_ = 0;
			float currentTimeInMs_;


			size_t index(const NeuronId origin, const NeuronId destination) const
			{
				return (origin * nNeurons) + destination;
			}
		};
	}
}