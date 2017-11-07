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

#include <limits>		// for std::numeric_limits
#include <cstdint>		// for std::int8_t

#include "../../Spike-Tools-LIB/SpikeTypes.hpp"

namespace spike
{
	namespace v1
	{
		///////////////////////////////////////////
		// spike types
		using SynapseLength = unsigned char;
		using Synapse = unsigned char;
		using Weight2 = float;

		using GroupId = unsigned short;

		struct Pathway
		{
			NeuronId destination;	// neuronId
			NeuronId origin;		// presynaptic neuronId
			Delay delay;			// delay from presynaptic neuron to neuron
			Weight2 weight;			// weight 

			// todo make a toString
		};

		struct Link
		{
			NeuronId destination;
			NeuronId origin;
			Delay delay;
			unsigned short layer;
		};

		struct Pre
		{
			NeuronId origin;	// contains neuronId that feeds into the provided index neuronId 
			Delay delay;		// contains delay of the neuron (in pre_i) that feeds into the provided index neuronId
		};
	}
}