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

#include "../../Spike-Tools-Lib/assert.ipp"

#include "../../Spike-Tools-LIB/SpikeRuntimeOptions.hpp"
#include "../../Spike-Tools-LIB/SpikeSet1Sec.hpp"
#include "../../Spike-Tools-LIB/Constants.hpp"

#include "../../Spike-Izhikevich-LIB/Topology.hpp"
#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"
#include "../../Spike-Izhikevich-LIB/v1/SpikeNetwork1.hpp"

namespace spike
{
	namespace v4
	{

		using namespace spike::tools;

		class DumperWeightDelta4
		{
		public:

			DumperWeightDelta4() = default;
			~DumperWeightDelta4() = default;

			DumperWeightDelta4(const SpikeRuntimeOptions& options)
				: options_(options)
			{
			}

			DumperWeightDelta4& operator=(const DumperWeightDelta4 &d) = default;

			void clear()
			{
				this->data_.clear();
			}

			bool dumpTest(const unsigned int sec) const
			{
				return (this->options_.isDumpToFileOn_WeightDelta() && ((sec % this->options_.getDumpIntervalInSec_WeightDelta()) == 0));
			}

			void store_WeightDelta(
				const float t,
				const NeuronId origin,
				const NeuronId destination,
				const double wD)
			{
				::tools::assert::assert_msg(t >= 0, "provided t (", t, ") is too small");
				::tools::assert::assert_msg(t < 1000, "provided t (", t, ") is too large");
				if (wD != 0)
				{
					//std::cout << "spike::v4::DumperWeightDelta4:store_WeightDelta: wD=" << wD << std::endl;
					this->data_.push_back(std::make_tuple(t, origin, destination, wD));
				}
			}

			void dump(
				const unsigned int sec,
				const std::string& nameSuffix)
			{
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
				FILE * const fs = fopen(filename.c_str(), "w");
				if (fs == nullptr)
				{
					std::cerr << "DumperWeightDelta::dump: Unable to open file " << filename << std::endl;
					throw std::runtime_error("unable to open file");
				}

				const size_t nWeightDeltas = this->data_.size();

				fprintf(fs, "#state <second> <nWeightDeltas>\n");
				fprintf(fs, "%u %zu\n", sec, nWeightDeltas);
				fprintf(fs, "#weightDelta <t> <origin> <destination> <weightDelta>\n");

				for (size_t i = 0; i < nWeightDeltas; ++i)
				{
					const auto result = this->data_[i];
					const float t = std::get<0>(result);
					const NeuronId origin = std::get<1>(result);
					const NeuronId destination = std::get<2>(result);
					const double timeDiff = std::get<3>(result);

					fprintf(fs, "%4.2f %u %u %f\n", t, origin, destination, timeDiff);
				}
				fclose(fs);

				this->clear();
			}

		private:

			const SpikeRuntimeOptions options_;
			std::vector<std::tuple<float, NeuronId, NeuronId, double>> data_;

		};
	}
}