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
#include <array>
#include <unordered_map>

#include "../../Spike-Tools-LIB/SpikeRuntimeOptions.hpp"

namespace spike
{
	namespace tools
	{

		template <size_t nNeurons, size_t nSubMs>
		class DumperState4
		{
		public:

			DumperState4() = default;
			DumperState4(const DumperState4<nNeurons, nSubMs>&) = default;
			~DumperState4() = default;

			DumperState4(const SpikeRuntimeOptions& spikeRuntimeOptions)
				: spikeRuntimeOptions_(spikeRuntimeOptions)
			{
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					this->dataTime_.push_back(std::vector<float>(0));
					this->dataV_.push_back(std::vector<float>(0));
					this->dataU_.push_back(std::vector<float>(0));
					this->dataIC_.push_back(std::vector<float>(0));
				}
			}

			DumperState4<nNeurons, nSubMs>& operator=(const DumperState4<nNeurons, nSubMs> &d) = delete;

			void clear()
			{
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					this->dataTime_[neuronId].clear();
					this->dataV_[neuronId].clear();
					this->dataU_[neuronId].clear();
					this->dataIC_[neuronId].clear();
				}
			}

			bool dumpTest(const unsigned int sec) const
			{
				return (this->spikeRuntimeOptions_.isDumpToFileOn_State() && ((sec % this->spikeRuntimeOptions_.getDumpIntervalInSec_State()) == 0));
			}

			void store(
				const NeuronId neuronId,
				const int timeInMs,
				const int timeSubMs,
				const float v,
				const float u,
				const float ic)
			{
				this->dataTime_[neuronId].push_back(timeInMs + static_cast<float>(timeSubMs) / nSubMs);
				this->dataV_[neuronId].push_back(v);
				this->dataU_[neuronId].push_back(u);
				this->dataIC_[neuronId].push_back(ic);
			}

			void dump(
				const unsigned int sec,
				const std::string& nameSuffix)
			{
				this->dumpToFile_printf(sec, nameSuffix);
			}

		private:

			const SpikeRuntimeOptions spikeRuntimeOptions_;

			std::vector<std::vector<float>> dataTime_;
			std::vector<std::vector<float>> dataV_;
			std::vector<std::vector<float>> dataU_;
			std::vector<std::vector<float>> dataIC_;


			void dumpToFile_printf(
				const unsigned int sec,
				const std::string& nameSuffix)
			{
				// create the filename
				std::stringstream filenameStream;
				if (nameSuffix.empty() || nameSuffix.length() == 0)
				{
					filenameStream << this->spikeRuntimeOptions_.getFilenamePath_State() << "/" << this->spikeRuntimeOptions_.getFilenamePrefix_State() << "." << sec << ".txt";
				}
				else
				{
					filenameStream << this->spikeRuntimeOptions_.getFilenamePath_State() << "/" << this->spikeRuntimeOptions_.getFilenamePrefix_State() << "." << nameSuffix << "." << sec << ".txt";
				}
				const std::string filename = filenameStream.str();

				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "spike::tools::DumperState::dumpToFile_printf(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				FILE * const fs = fopen(filename.c_str(), "w");
				if (fs == nullptr)
				{
					std::cerr << "spike::tools::DumperState::dumpToFile_printf: Error: could not write to file " << filename << std::endl;
					return;
				}
				fprintf(fs, "#state <second> <nNeurons>\n");
				fprintf(fs, "%u %zu\n", sec, nNeurons);

				fprintf(fs, "#stateData <neuronId> <ms> <v> <u> <ic>\n");
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					for (size_t i = 0; i < this->dataTime_[neuronId].size(); ++i)
					{

						const float v = this->dataV_[neuronId][i];
						const float u = this->dataU_[neuronId][i];
						const float ic = this->dataIC_[neuronId][i];

						fprintf(fs, "%u %f ", neuronId, this->dataTime_[neuronId][i]);
						if (std::isnan(v))
						{
							fprintf(fs, "nan ");
						}
						else
						{
							fprintf(fs, "%f ", v);
						}
						if (std::isnan(u))
						{
							fprintf(fs, "nan ");
						}
						else
						{
							fprintf(fs, "%f ", u);
						}
						if (std::isnan(ic))
						{
							fprintf(fs, "nan\n");
						}
						else
						{
							fprintf(fs, "%f\n", ic);
						}
					}
				}

				this->clear();
				fclose(fs);
			}
		};
	}
}