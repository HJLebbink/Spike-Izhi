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

#include "../../Spike-Tools-Lib/assert.ipp"

namespace spike
{
	namespace v2
	{
		template <size_t nNeurons, size_t maxDelay>
		class InputCurrent2
		{

		private:

			static const size_t sizeTime = 1001 + maxDelay;
			std::array<float, nNeurons> * data_[sizeTime];

		public:

			// destructor
			~InputCurrent2()
			{
				for (size_t i = 0; i < sizeTime; ++i)
				{
					free(this->data_[i]);
				}
			}

			// constructor
			InputCurrent2()
			{
				for (size_t i = 0; i < sizeTime; ++i)
				{
					auto p = new std::array<float, nNeurons>();
					p->fill(0);

					this->data_[i] = p;
				}
			}

			const float * getPtr(const unsigned int t) const
			{
				return (*this->data_[t]).data();
			}

			template <NeuronId neuronId, Delay d>
			void add(const unsigned int t, const float w)
			{
				(*this->data_[t + d])[neuronId] += w;
			}

			void add(const NeuronId neuronId, const Delay d, const unsigned int t, const float w)
			{
				(*this->data_[t + d])[neuronId] += w;
			}

			void clean()
			{
				for (size_t i = 0; i < sizeTime; ++i)
				{
					this->data_[i]->fill(0);
				}
			}

			void resetTime()
			{
				for (size_t i = 0; i < maxDelay; ++i)
				{
					std::swap(this->data_[i], this->data_[1000 + i]);
				}
				for (size_t i = maxDelay; i < sizeTime; ++i)
				{
					this->data_[i]->fill(0);
				}
			}
		};
	}
}