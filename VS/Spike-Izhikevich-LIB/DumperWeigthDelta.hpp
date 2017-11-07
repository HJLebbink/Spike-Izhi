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
		using namespace spike::tools;

		class DumperWeightDelta
		{
		public:

			//DumperWeightDelta() = delete;
			~DumperWeightDelta() = default;

			DumperWeightDelta(const SpikeRuntimeOptions& options)
				: options_(options)
			{
			}

			//DumperWeightDelta& operator=(const DumperWeightDelta &d) = delete;

			void clear()
			{
				this->data_.clear();
			}

			bool dumpTest(const unsigned int sec) const
			{
				return (this->options_.isDumpToFileOn_WeightDelta() && ((sec % this->options_.getDumpIntervalInSec_WeightDelta()) == 0));
			}

			void store_WeightDelta(
				const unsigned int t,
				const NeuronId origin,
				const NeuronId destination,
				const int timeDiffInMs)
			{
				::tools::assert::assert_msg(t < 1000, "provided t (", t, ") is too large");
				if (timeDiffInMs != 0) this->data_.push_back(std::make_tuple(t, origin, destination, timeDiffInMs));
			}

			void dump(
				const unsigned int sec,
				const std::string& nameSuffix)
			{
				// mutex to protect file access
				//static std::mutex mutex;

				// lock mutex before accessing file
				//std::lock_guard<std::mutex> lock(mutex);

				// create the filename
				std::stringstream filenameStream;
				if (nameSuffix.empty() || nameSuffix.length() == 0)
				{
					filenameStream << this->options_.getFilenamePath_WeightDelta() << "/" << this->options_.getFilenamePrefix_WeightDelta() << "." << sec << ".txt";
				}
				else
				{
					filenameStream << this->options_.getFilenamePath_WeightDelta() << "/" << this->options_.getFilenamePrefix_WeightDelta() << "." << nameSuffix << "." << sec << ".txt";
				}
				const std::string filename = filenameStream.str();

				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				//std::cout << "making directory " << tree << " for filename " << filename << std::endl;
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "DumperWeightDelta::dump(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				// try to open file
				std::ofstream outputFile(filename); //fstream is a proper RAII object, it does close automatically at the end of the scope
				if (!outputFile.is_open())
				{
					std::cerr << "DumperWeightDelta::dump: Unable to open file " << filename << std::endl;
					throw std::runtime_error("unable to open file");
				}
				else
				{

					const size_t nWeightDeltas = this->data_.size();

					outputFile << "#state <second> <nWeightDeltas>" << std::endl;
					outputFile << sec << " " << nWeightDeltas << std::endl;

					outputFile << "#weightDelta <t> <origin> <destination> <weightDelta>" << std::endl;

					for (size_t i = 0; i < nWeightDeltas; ++i)
					{
						const auto result = this->data_[i];
						const unsigned int t = std::get<0>(result);
						const NeuronId origin = std::get<1>(result);
						const NeuronId destination = std::get<2>(result);
						const int timeDiff = std::get<3>(result);
						outputFile << t << " " << origin << " " << destination << " " << timeDiff << std::endl;
					}
				}
				this->clear();
			}

		private:

			const SpikeRuntimeOptions options_;
			std::vector<std::tuple<unsigned int, NeuronId, NeuronId, int>> data_;

		};
	}
}