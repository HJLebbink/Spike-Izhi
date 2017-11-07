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
#include <set>
#include <deque>
#include <iostream> // for cerr and cout
#include <memory>

#include "../../../matio-1.5.2/src/matio.h"

#include "../../Spike-Tools-LIB/SpikeRuntimeOptions.hpp"
#include "../../Spike-Izhikevich-LIB/v4/SpikeClassification4.hpp"

namespace spike
{
	namespace v4
	{

		using namespace ::spike::tools;

		template <size_t nNeurons, size_t nSubMs>
		class SpikeDataSetMatlab4
		{
		public:

			using TimeType = TimeInMsI;


			// destructor
			//~SpikeDataSetMatlab4() = default;

			// constructor
			SpikeDataSetMatlab4() = delete;

			// constructor
			SpikeDataSetMatlab4(const SpikeRuntimeOptions& spikeRunTimeOptions)
				: spikeRunTimeOptions_(spikeRunTimeOptions)
			{
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
				{
					this->ms_.push_back(std::vector<unsigned int>());
					this->subMs_.push_back(std::vector<unsigned short>());
					this->pos_.push_back(0);
					this->atEnd_.push_back(true);
				}
			}

			// copy constructor
			//SpikeDataSetMatlab4(const SpikeDataSetMatlab4&) = default;

			// assignment
			//SpikeDataSetMatlab4 & operator=(const SpikeDataSetMatlab4&) = default;

			void setClassificationFilename(const std::string& filename)
			{
				this->classificationFilename_ = filename;
			}

			void load(const std::string& filename, const unsigned int maxTimeInMsToLoad)
			{
				this->loadInputData(filename, maxTimeInMsToLoad);
				this->loadClassification(maxTimeInMsToLoad);
			}

			float latency(const float spikeTimeInMs, const CaseId caseId) const
			{
				return this->spikeClassification_.latency(spikeTimeInMs, caseId);
			}

			void saveToFile(const std::string& filename) const
			{
				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "spike::masquelier::SpikeInputContainer::saveToFile(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				FILE * const fs = fopen(filename.c_str(), "w");
				if (fs == nullptr)
				{
					std::cerr << "spike::masquelier::SpikeInputContainer::saveToFile: Error: could not write to file " << filename << std::endl;
					return;
				}

				fprintf(fs, "#spike <second> <nCases> <nSpikes>\n");
				const unsigned int second = 0;
				const unsigned int nCases = 0;
				const unsigned int nSpikes = this->getNumberOfSpikes();
				fprintf(fs, "%u %u %u\n", second, nCases, nSpikes);

				fprintf(fs, "#caseOccurance <caseId> <startTimeInMs> <endTimeInMs>\n");

				fprintf(fs, "#spikeData <timeInMs> <neuronId> <firingReason> (UNKNOWN = 0, PROPAGATED = 1, RANDOM = 2, CASE = 3, PROPAGATED_AND_CASE = 4, FORCED = 5)\n");

				for (unsigned int i = 0; i < nSpikes; ++i)
				{
					//const SpikeEvent spikeEvent = this->spikeEvent_[i];
					//const SpikeNeuronId neuronId = getOriginatingNeuronIdFromSpikeEvent(spikeEvent);
					//const SpikeTime spikeTime = getTimeFromSpikeEvent(spikeEvent);
					//const float timeInMsFloat = static_cast<float>(spikeTime) / TIME_DENOMINATOR;
					//const unsigned int timeInMs = static_cast<unsigned int>(trunc(timeInMsFloat));
					//fprintf(fs, "%d %d %d\n", timeInMs, neuronId, 5);
				}
				fclose(fs);
			}

			const std::vector<CaseId> getCaseIds() const
			{
				return this->spikeClassification_.getCaseIds();
			}

			// true/false; 
			std::tuple<bool, unsigned short> getInputSpike(const NeuronId neuronId, const unsigned int ms)
			{
				if (neuronId >= nNeurons)
				{
					return std::make_tuple(false, 0);
				}
				if (this->atEnd_[neuronId])
				{
					return std::make_tuple(false, 0);
				}
				else
				{
					unsigned int pos = this->pos_[neuronId];
					const std::vector<unsigned int>& v = this->ms_[neuronId];
					const size_t size = v.size();

					while (v[pos] < ms)
					{
						pos++;
						if (pos >= size)
						{
							this->atEnd_[neuronId] = true;
							return std::make_tuple(false, 0);
						}
					}

					if (v[pos] == ms)
					{
						const std::tuple<bool, unsigned short> tuple = std::make_tuple(true, this->subMs_[neuronId][pos]);
						pos++;
						if (pos >= size)
						{
							this->atEnd_[neuronId] = true;
						}
						else
						{
							this->pos_[neuronId] = pos;
						}
						return tuple;
					}
					else
					{
						this->pos_[neuronId] = pos;
						return std::make_tuple(false, 0);
					}
				}
			}

		private:

			const SpikeRuntimeOptions spikeRunTimeOptions_;

			std::vector<std::vector<unsigned int>> ms_;
			std::vector<std::vector<unsigned short>> subMs_;
			std::vector<unsigned int> pos_;
			std::vector<bool> atEnd_;

			unsigned int lastMs_;

			std::string classificationFilename_;
			SpikeClassification4 spikeClassification_;


			void loadClassification(const unsigned int /*maxTimeInMs*/)
			{
				this->spikeClassification_.load(this->classificationFilename_);
			}

			void loadInputData(const std::string& filename, const unsigned int maxTimeInMsToLoad)
			{
				std::vector<long long> lastSpikeTimeInMs(2000, -1);
				unsigned long long nIgnoredSpikes = 0;


				const std::string variableName1 = "spikeList";
				const std::string variableName2 = "afferentListDouble";

				mat_t *mat;
				matvar_t *matvar1;
				matvar_t *matvar2;
				size_t i = 0;

				mat = Mat_Open(filename.c_str(), MAT_ACC_RDONLY);
				if (mat)
				{
					matvar1 = Mat_VarRead(mat, (char*)variableName1.c_str());
					matvar2 = Mat_VarRead(mat, (char*)variableName2.c_str());

					if ((matvar1 == NULL) || (matvar2 == NULL))
					{
						std::cerr << "spike::v4::SpikeDataSetMatlab4::loadInputData: error" << std::endl;
						//DEBUG_BREAK();
					}
					else
					{
						Mat_VarReadDataAll(mat, matvar1);
						Mat_VarReadDataAll(mat, matvar2);

						const size_t length1 = matvar1->dims[1];
						const size_t length2 = matvar2->dims[1];

						if (length1 != length2)
						{
							std::cerr << "spike::v4::SpikeDataSetMatlab4::loadInputData: sizes do not match " << std::endl;
							throw std::runtime_error("spike::v4::SpikeDataSetMatlab4::loadInputData: sizes do not match");
						}

						char * data1 = (char *)matvar1->data;
						char * data2 = (char *)matvar2->data;
						const size_t stride1 = Mat_SizeOf(matvar1->data_type);
						const size_t stride2 = Mat_SizeOf(matvar2->data_type);

						bool continueLoading = true;
						while (continueLoading && (i < length1))
						{
							if ((i & 0xFFFFF) == 0) std::cout << "spike::v4::SpikeDataSetMatlab4::loadInputData: loaded " << i << " spikes" << std::endl;

							const double timeInSec = *(double *)(data1 + (i*stride1));
							const double afferentDouble = *(double *)(data2 + (i*stride2));

							const unsigned int ms = static_cast<unsigned int>(timeInSec * 1000);
							const double subMsDouble = (timeInSec * 1000) - ms;
							const unsigned short subMs = static_cast<unsigned short>(subMsDouble * nSubMs);

							//std::cout << "timeInSec=" << timeInSec << "; ms=" << ms << "; subMsDouble=" << subMsDouble << "; subMs=" << subMs << std::endl;

							if (ms > maxTimeInMsToLoad)
							{
								continueLoading = false;
								break;
							}
							else
							{
								const NeuronId afferent = static_cast<NeuronId>(afferentDouble) - 1; // minus one because the matlab file starts counting neurons at 1.


								const long long timeBetweenPreviousSpike = static_cast<long long>(ms) - lastSpikeTimeInMs[afferent];
								if (timeBetweenPreviousSpike >= 1)
								{
									this->lastMs_ = ms;
									this->storeSpike(afferent, ms, subMs);
									lastSpikeTimeInMs[afferent] = static_cast<long long>(ms);
								}
								else
								{
									nIgnoredSpikes++;
									//printf("spike:v4::SpikeDataSetMatlab4::loadInputData: neuron %u; previous spike at %llu ms, current spike at %llu ms; time between=%llu ms\n", afferent, lastSpikeTimeInMs[afferent], ms, timeBetweenPreviousSpike);
								}
								i++;
							}
						}
					}
					Mat_VarFree(matvar1);
					Mat_VarFree(matvar2);
					Mat_Close(mat);
				}
				else
				{
					std::cerr << "spike::v4::SpikeDataSetMatlab4::loadInputData: could not load file " << filename << std::endl;
					throw std::runtime_error("spike::masquelier::SpikeInputContainerMatlab::load:: could not load file");
				}
				std::cout << "spike::v4::SpikeDataSetMatlab4::loadInputData: done loading " << i << " spikes; " << nIgnoredSpikes << " spikes ignored." << std::endl;
			}

			void storeSpike(const NeuronId neuronId, const unsigned int ms, const unsigned short subMs)
			{
				if (subMs >= nSubMs)
				{
					std::cout << "spike::v4::SpikeDataSetMatlab4::storeSpike: subMs (" << subMs << ") is too large; nSubMs = " << nSubMs << std::endl;
					//DEBUG_BREAK();
				}
				if (neuronId < nNeurons)
				{
					this->ms_[neuronId].push_back(ms);
					this->subMs_[neuronId].push_back(subMs);
					this->atEnd_[neuronId] = false;
				}
			}
		};
	}
}