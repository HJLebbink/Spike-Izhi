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

#include "../../Spike-Tools-LIB/SpikeTypes.hpp"

namespace spike
{
	namespace v2
	{

		template <typename T>
		class LoopRangeIterator2
		{
		public:
			LoopRangeIterator2(const T * const ptr)
				: ptr_(ptr)
			{
				static_assert(std::is_integral<T>::value, "LoopRangeIterator: range only accepts integral values");
			}

			bool operator!=(const LoopRangeIterator2& other) const
			{
				return this->ptr_ != other.ptr_;
			}

			const T& operator*() const
			{
				return *this->ptr_;
			}

			void operator++()
			{
				++this->ptr_;
			}

		private:
			const T * ptr_;
		};

		class NeuronIdRange2
		{
		public:

			NeuronIdRange2(const NeuronId * const ptr, const size_t s)
				: ptrBegin_(ptr)
				, ptrEnd_(ptr + s)
			{
			}

			LoopRangeIterator2<NeuronId> begin() const
			{
				return LoopRangeIterator2<NeuronId>(this->ptrBegin_);
			}

			const LoopRangeIterator2<NeuronId> end() const
			{
				return LoopRangeIterator2<NeuronId>(this->ptrEnd_);
			}

		private:

			const NeuronId * const ptrBegin_;
			const NeuronId * const ptrEnd_;

		};
	}
}