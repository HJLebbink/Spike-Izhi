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
#include <vector>
#include <memory> // for make_unique, unique_ptr

#include "../../Spike-Tools-LIB/SpikeRuntimeOptions.hpp"
#include "../../Spike-Tools-LIB/SpikeSet1Sec.hpp"
#include "../../Spike-Tools-LIB/Constants.hpp"

#include "../../Spike-Izhikevich-LIB/Topology.hpp"
#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"
#include "../../Spike-Izhikevich-LIB/v1/SpikeNetwork1.hpp"

namespace spike
{
	namespace v1
	{

		template <typename SpikeNetwork_i>
		class Search_Network_Config
		{
		public:

			using SpikeNetwork = SpikeNetwork_i;
			using Topology = typename SpikeNetwork_i::Topology;

			static const size_t nNeurons = Topology::nNeurons;


			// destructor
			~Search_Network_Config() = default;

			// constructor
			Search_Network_Config() = delete;

			// constructor
			Search_Network_Config(const SpikeRuntimeOptions& spikeRuntimeOptions)
				: spikeRuntimeOptions_(spikeRuntimeOptions)
			{
			}

			Search_Network_Config& operator=(const Search_Network_Config &d) = delete;

			void run()
			{
				const unsigned int trainTimeInSec = 1 * 1 * 60 * 60;

				const bool useConfusionMatrix = true;
				const bool plotProgress = false;

				const auto spikeNetwork = std::make_shared<SpikeNetwork>(this->spikeRuntimeOptions_);
				const auto stream = this->loadMnistSpikeStream();
				spikeNetwork->setSpikeStream(stream);

				std::vector<float> parameterA_Space;
				float parameterA_tmp = 0;
				for (unsigned int i = 0; i < 20; ++i)
				{
					parameterA_Space.push_back(parameterA_tmp);
					parameterA_tmp += 0.01f;
				}

				std::vector<float> parameterB_Space;
				float parameterB_tmp = -1;
				for (unsigned int i = 0; i < 20; ++i)
				{
					parameterB_Space.push_back(parameterB_tmp);
					parameterB_tmp += 0.05f;
				}

				for (const float parameterA : parameterA_Space)
				{
					for (const float parameterB : parameterB_Space)
					{

						std::cout << "parameterA = " << parameterA << "; parameterB = " << parameterB << std::endl;

						//1 load topology
						const auto topology = std::make_shared<Topology>();
						if (false)
						{
							topology->load_mnist14x14();
						}
						else
						{
							topology->loadFromFile(tempDir + "/topology-mnist.train.32400.txt");
						}

						//2.a set properties of certain neurons based on the run number
						for (NeuronId neuronId = 196; neuronId < 196 + 10; ++neuronId)
						{
							topology->setParameterA(neuronId, parameterA);
							topology->setParameterB(neuronId, parameterB);
						}

						//2.b reset certain weights 
						for (NeuronId neuronId = 196; neuronId < 196 + 10; ++neuronId)
						{
							for (const NeuronId incommingNeuron : topology->getIncommingNeurons(neuronId))
							{
								topology->setWeight(incommingNeuron, neuronId, 6.0f);
							}
						}

						//3] assing the topology to the network
						spikeNetwork->setTopology(topology);

						//4] train the network
						spikeNetwork->train(trainTimeInSec, useConfusionMatrix, plotProgress);

						//5] print or write to file the topology parameters and the average precision
						std::cout << spikeNetwork->spikeNetworkPerformance_.toStringConfusionMatrix() << std::endl;
						std::cout << "averagePrecision " << spikeNetwork->spikeNetworkPerformance_.getAveragePrecision() << std::endl;
						spikeNetwork->spikeNetworkPerformance_.clear();
					}
				}
			}

		private:

			const SpikeRuntimeOptions spikeRuntimeOptions_;

			std::shared_ptr<SpikeStream<Topology>> loadMnistSpikeStream()
			{
				const auto spikeStream = std::make_shared<SpikeStream<Topology>>(this->spikeRuntimeOptions_);

				//2 load the spike data
				const std::string spikeDataSetFilename = "C:/Data/mnist data/14x14/SpikeDataSetMnist-test-only10-train-14x14.txt";
				const auto spikeDataSet = std::make_shared<SpikeDataSet<MyDataType>>();
				spikeDataSet->loadFromFile(spikeDataSetFilename);

				//3 add the spike data to the stream
				spikeStream->addSpikeDataSet(spikeDataSet);

				return spikeStream;
			}

		};
	}
}