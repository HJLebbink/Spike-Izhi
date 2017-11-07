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
#include <tuple>
#include <iostream> // for cerr and cout

namespace spike
{
	namespace v4
	{

		class SpikeEpspContainer4
		{
		public:

			~SpikeEpspContainer4()
			{
				this->close();
			}

			SpikeEpspContainer4()
				: SpikeEpspContainer4(true)
			{
			}

			SpikeEpspContainer4(const bool syncToFile)
				: syncToFile_(syncToFile)
			{
			}

			void setOutputFilename(const std::string& outputFilename)
			{
				std::cout << "spike::v4:SpikeEpspContainer4::setOutputFilename ================================" << std::endl;
				std::cout << "spike::v4:SpikeEpspContainer4::setOutputFilename: setting output file = " << outputFilename << std::endl;

				// create the directory
				const std::string tree = ::tools::file::getDirectory(outputFilename);
				//std::cout << "making directory " << tree << " for filename " << filename << std::endl;
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "DumperWeightDelta::dump(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				// try to open file
				this->fs_ = fopen(outputFilename.c_str(), "w");
				if (this->fs_ == nullptr)
				{
					std::cerr << "DumperWeightDelta::dump: Unable to open file " << outputFilename << std::endl;
					throw std::runtime_error("unable to open file");
				}

				std::cout << "spike::v4:SpikeEpspContainer4:: ================================" << std::endl;
			}

			void storeSpikeEvent(const int neuronId, const double timeInSec)
			{
				//std::cout << "spike::v4::SpikeEpspContainer: storeSpikeEvent: neuronId=" << neuronId << "; timeInSec=" << timeInSec << std::endl;
				this->outputEvents_.push_back(std::make_tuple(neuronId, timeInSec));

				if (this->syncToFile_)
				{
					this->writeToFile(neuronId, timeInSec);
					fflush(this->fs_);
				}
			}

			void writeToFile(const int neuronId, const double timeInSec)
			{
				//std::cout << "spike::v4::SpikeEpspContainer: writeToFile: timeInSec=" << timeInSec << std::endl;
				fprintf(this->fs_, "%f %i\n", timeInSec, neuronId);
			}

			void close()
			{
				if (!this->syncToFile_)
				{
					for (size_t i = 0; i < this->outputEvents_.size(); ++i)
					{
						this->writeToFile(std::get<0>(this->outputEvents_[i]), std::get<1>(this->outputEvents_[i]));
					}
				}
				fclose(this->fs_);
			}

		private:

			bool syncToFile_;

			std::vector<std::tuple<int, double>> outputEvents_;
			FILE * fs_;
		};
	}
}