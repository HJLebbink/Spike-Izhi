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
		template <size_t nNeurons>
		class DumperState
		{
		public:

			~DumperState() = default;

			DumperState(const SpikeRuntimeOptions& spikeRuntimeOptions)
				: spikeRuntimeOptions_(spikeRuntimeOptions)
			{
				this->u_.resize(1000 * nNeurons);
				this->v_.resize(1000 * nNeurons);
				this->ic_.resize(1000 * nNeurons);
				this->clear();
			}

			void clear()
			{
				std::fill(this->u_.begin(), this->u_.begin() + 1000 * nNeurons, 0.0f);
				std::fill(this->v_.begin(), this->v_.begin() + 1000 * nNeurons, 0.0f);
				std::fill(this->ic_.begin(), this->ic_.begin() + 1000 * nNeurons, 0.0f);
			}

			bool dumpTest(const unsigned int sec) const
			{
				return (this->spikeRuntimeOptions_.isDumpToFileOn_State() && ((sec % this->spikeRuntimeOptions_.getDumpIntervalInSec_State()) == 0));
			}

			void store_State(
				const Ms t,
				const float v[],
				const float u[],
				const float ic[])
			{
				::tools::assert::assert_msg(t >= 0, "provided t (", t, ") is too small");
				::tools::assert::assert_msg(t < 1000, "provided t (", t, ") is too large");

				const unsigned int offset = t * 1000;
				for (unsigned int i = 0; i < nNeurons; ++i)
				{
					this->v_[offset + i] = v[i];
					this->u_[offset + i] = u[i];
					this->ic_[offset + i] = ic[i];
				}
			}

			void dump(
				const unsigned int sec,
				const std::string& nameSuffix)
			{
				//this->dumpToFile_stream(sec, nameSuffix);
				this->dumpToFile_printf(sec, nameSuffix);
			}

		private:

			const SpikeRuntimeOptions spikeRuntimeOptions_;

			std::vector<float> v_;
			std::vector<float> u_;
			std::vector<float> ic_;

			void dumpToFile_stream(
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
				//std::cout << "making directory " << tree << " for filename " << filename << std::endl;
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "Spike_Network_Dump_State::dumpToFile_State(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				// try to open file
				std::ofstream outputFile(filename); //fstream is a proper RAII object, it does close automatically at the end of the scope
				if (!outputFile.is_open())
				{
					std::cerr << "Spike_Network_Dump_State::dumpToFile_State(): Unable to open file " << filename << std::endl;
					throw std::runtime_error("unable to open file");
				}
				else
				{

					outputFile << "#state <second> <nNeurons>" << std::endl;
					outputFile << sec << " " << nNeurons << std::endl;

					outputFile << "#stateData <neuronId> <ms> <v> <u> <ic>" << std::endl;
					for (Ms t = 0; t < 1000; ++t)
					{
						const unsigned int offset = t * 1000;

						for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
						{
							const unsigned int offset2 = offset + neuronId;

							outputFile << neuronId << " " << t << " " << this->v_[offset2] << " " << this->u_[offset2] << " " << this->ic_[offset2] << std::endl;
						}
					}
				}
				this->clear();
			}

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
					std::cerr << "Spike_Network_Dump_State::dumpToFile_printf(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				FILE * const fs = fopen(filename.c_str(), "w");
				if (fs == nullptr)
				{
					std::cerr << "Spike_Network_Dump_State::dumpToFile_printf: Error: could not write to file " << filename << std::endl;
					return;
				}
				fprintf(fs, "#state <second> <nNeurons>\n");
				fprintf(fs, "%u %zu\n", sec, nNeurons);

				fprintf(fs, "#stateData <neuronId> <ms> <v> <u> <ic>\n");
				for (Ms t = 0; t < 1000; ++t)
				{
					const unsigned int offset = t * 1000;

					for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
					{
						const unsigned int offset2 = offset + neuronId;
						fprintf(fs, "%u %d %f %f %f\n", neuronId, t, this->v_[offset2], this->u_[offset2], this->ic_[offset2]);
					}
				}
				this->clear();
				fclose(fs);
			}
		};
	}
}