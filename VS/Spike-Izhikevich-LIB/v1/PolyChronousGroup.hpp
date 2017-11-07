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

#include "../../Spike-Tools-LIB/SpikeSet1Sec.hpp"

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"

namespace spike
{
	namespace v1
	{

		class PolyChronousGroup
		{
		public:

			// destructor
			~PolyChronousGroup() = default;

			// constructor
			PolyChronousGroup(const GroupId id)
				: id_(id)
				, caseId_(NO_CASE_ID)
			{
			}

			// copy constructor deleted
			PolyChronousGroup(const PolyChronousGroup&) = delete;

			// assignement deleted
			PolyChronousGroup & operator=(const PolyChronousGroup&) = delete;

			void clear()
			{
				this->caseId_ = NO_CASE_ID;
				this->anchorFirings_.clear();
				this->regularFirings_.clear();
				this->links_.clear();
			}

			void saveToFile(const std::string& filename) const
			{
				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "PolyChronousGroup::saveToFile(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				std::stringstream fullFilenameStream;
				fullFilenameStream << filename << "." << this->id_ << ".txt";
				const std::string fullFilename = fullFilenameStream.str();
				FILE * const fs = fopen(fullFilename.c_str(), "w");
				if (fs == nullptr)
				{
					std::cerr << "PolyChronousGroup::saveToFile(): Error: could not write to file " << fullFilename << std::endl;
					return;
				}

				const std::set<Firing> anchorFiring = this->getAnchorFirings();
				const std::set<Firing> regularFiring = this->getRegularFirings();

				fprintf(fs, "#<nAnchorNeurons> <nFired> <nLinks> <caseId>\n");
				fprintf(fs, "%zu %zu %zu %d\n", anchorFiring.size(), regularFiring.size(), this->links_.size(), this->caseId_.val);

				fprintf(fs, "#anchorfirings <timeInMs> <neuronId>\n");
				for (const Firing& firing : anchorFiring)
				{
					fprintf(fs, "%d %u\n", firing.time, firing.neuronId);
				}

				fprintf(fs, "#regularfiring <timeInMs> <neuronId>\n");
				for (const Firing& firing : regularFiring)
				{
					fprintf(fs, "%d %u\n", firing.time, firing.neuronId);
				}

				fprintf(fs, "#link <origin> <destination> <delayInMs> <layer>\n");
				for (unsigned int i = 0; i < static_cast<unsigned int>(this->links_.size()); i++)
				{
					const Link link = this->links_[i];
					fprintf(fs, "%u %u %d %d\n", link.origin, link.destination, link.delay, link.layer);
				}

				fclose(fs);
			}

			void saveGroupMatch(const std::string& filename, const SpikeSet1Sec<Ms>& spikeData) const
			{
				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "PolyChronousGroup::saveToFile(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				std::stringstream fullFilenameStream;
				fullFilenameStream << filename << "." << this->id_ << ".txt";
				const std::string fullFilename = fullFilenameStream.str();
				FILE * const fs = fopen(fullFilename.c_str(), "w");
				if (fs == nullptr)
				{
					std::cerr << "PolyChronousGroup::saveGroupMatch(): Error: could not write to file " << fullFilename << std::endl;
					return;
				}

				const std::set<Firing> anchorFiring = this->getAnchorFirings();
				const std::set<Firing> regularFiring = this->getRegularFirings();


				fprintf(fs, "#<nAnchorNeurons> <nFired> <nLinks> <caseId>\n");
				fprintf(fs, "%zu %zu %zu %d\n", this->anchorFirings_.size(), this->regularFirings_.size(), this->links_.size(), this->caseId_.val);

				fprintf(fs, "#anchorfirings <time> <neuronId>\n");
				for (const Firing& firing : anchorFiring)
				{
					fprintf(fs, "%d %u\n", firing.time, firing.neuronId);
				}

				fprintf(fs, "#regularfiring <time> <neuronId>\n");
				for (const Firing& firing : regularFiring)
				{
					fprintf(fs, "%d %u\n", firing.time, firing.neuronId);
				}

				fprintf(fs, "#link <origin> <destination> <delay> <layer>\n");
				for (size_t i = 0; i < this->links_.size(); i++)
				{
					const Link link = this->links_[i];
					fprintf(fs, "%u %u %d %d\n", link.origin, link.destination, link.delay, link.layer);
				}

				fprintf(fs, "#spikeData <timeInMs> <neuronId>\n");
				const Ms beginTime = 0;
				const Ms endTime = this->getLastFiringTime() + 10;

				const auto firingNeuronIdArray = spikeData.getFiringNeuronId();
				const std::vector<Ms> firingTimeArray = spikeData.getFiringTime();

				for (unsigned int i = 0; i < spikeData.getNumberOfFirings(); ++i)
				{
					const Ms firingTime = firingTimeArray[i];

					if ((firingTime >= beginTime) && (firingTime < endTime))
					{
						const NeuronId firingNeuronId = firingNeuronIdArray[i];

						for (const Firing firing : anchorFiring)
						{
							if (firing.neuronId == firingNeuronId)
							{
								fprintf(fs, "%d %u\n", firingTime, firing.neuronId);
							}
						}
						for (const Firing firing : regularFiring)
						{
							if (firing.neuronId == firingNeuronId)
							{
								fprintf(fs, "%d %u\n", firingTime, firing.neuronId);
							}
						}
					}
				}
				fclose(fs);
			}

			void loadFromFile(const std::string& filename)
			{
				std::stringstream fullFilenameStream;
				fullFilenameStream << filename << "." << this->id_ << ".txt";
				const std::string fullFilename = fullFilenameStream.str();
				std::ifstream inputFile(fullFilename);

				if (!inputFile.is_open())
				{
					std::cerr << "PolyChronousGroup::loadFromFile(): Unable to open file " << fullFilename << std::endl;
				}
				else
				{
					//std::cout << "PolyChronousGroup::loadFromFile(): Opening file " << fullFilename << std::endl;

					this->clear();
					std::string line;

					::tools::file::loadNextLine(inputFile, line);
					const std::vector<std::string> contentA = ::tools::file::split(line, ' ');
					const int nAnchorFirings = ::tools::file::string2int(contentA[0]);
					const int nRegularFired = ::tools::file::string2int(contentA[1]);
					const int nLinks = ::tools::file::string2int(contentA[2]);
					this->caseId_ = CaseId(static_cast<CaseIdType>(::tools::file::string2int(contentA[3])));

					{
						for (int i = 0; i < nAnchorFirings; i++)
						{
							::tools::file::loadNextLine(inputFile, line);
							const std::vector<std::string> content = ::tools::file::split(line, ' ');
							const Ms time = static_cast<Ms>(::tools::file::string2int(content[0]));
							const NeuronId neuronId = static_cast<NeuronId>(::tools::file::string2int(content[1]));
							this->addAnchorFiring(Firing(time, neuronId));
						}
					}
					{
						for (int i = 0; i < nRegularFired; i++)
						{
							::tools::file::loadNextLine(inputFile, line);
							const std::vector<std::string> content = ::tools::file::split(line, ' ');
							const Ms time = static_cast<Ms>(::tools::file::string2int(content[0]));
							const NeuronId neuronId = static_cast<NeuronId>(::tools::file::string2int(content[1]));
							this->addRegularFiring(Firing(time, neuronId));
						}
					}
					{
						for (int i = 0; i < nLinks; i++)
						{
							::tools::file::loadNextLine(inputFile, line);
							const std::vector<std::string> content = ::tools::file::split(line, ' ');
							Link link = {};
							link.origin = static_cast<NeuronId>(::tools::file::string2int(content[0]));
							link.destination = static_cast<NeuronId>(::tools::file::string2int(content[1]));
							link.delay = static_cast<Ms>(::tools::file::string2int(content[2]));
							link.layer = static_cast<unsigned short>(::tools::file::string2int(content[3]));
							this->addLink(std::move(link));
						}
					}
				}
			}

			void addAnchorFiring(const Firing firing)
			{
				if (!this->isRegularFiring(firing))
				{
					this->anchorFirings_.insert(firing);
				}
				else
				{
					//std::cout << "PolyChronousGroup::addAnchorFiring: WARNING: provided firing " << firing.toString() << " is already present in regular firings" << std::endl;
				}
			}

			void addRegularFiring(const Firing firing)
			{
				if (!this->isAnchorFiring(firing))
				{
					this->regularFirings_.insert(firing);
				}
				else
				{
					//std::cout << "PolyChronousGroup::addRegularFiring: WARNING: provided firing " << firing.toString() << " is already present in anchor firings" << std::endl;
				}
			}

			void addLink(const Link link)
			{
				this->links_.push_back(link);
			}

			unsigned int getNumberOfAnchorFirings() const
			{
				return static_cast<unsigned int>(this->anchorFirings_.size());
			}

			unsigned int getNumberOfRegularFirings() const
			{
				return static_cast<unsigned int>(this->regularFirings_.size());
			}

			bool isAnchorFiring(const Firing firing) const
			{
				return this->anchorFirings_.find(firing) != this->anchorFirings_.cend();
			}

			bool isRegularFiring(const Firing firing) const
			{
				return this->regularFirings_.find(firing) != this->regularFirings_.cend();
			}

			const std::set<Firing> getAnchorFirings() const
			{
				return this->anchorFirings_;
			}

			const std::set<Firing> getRegularFirings() const
			{
				return this->regularFirings_;
			}

			Ms getLastFiringTime() const
			{
				const Ms lastRegularFiringTime = (this->regularFirings_.empty()) ? 0 : (*this->regularFirings_.crend()).time;
				const Ms lastAnchorFiringTime = (this->anchorFirings_.empty()) ? 0 : (*this->anchorFirings_.crend()).time;
				if (lastRegularFiringTime > lastAnchorFiringTime)
				{
					return lastRegularFiringTime;
				}
				else
				{
					return lastAnchorFiringTime;
				}
			}

			CaseId getCaseId() const
			{
				return this->caseId_;
			}

			void setCaseId(const CaseId caseId)
			{
				this->caseId_ = caseId;
			}

			GroupId getGroupId() const
			{
				return this->id_;
			}

		private:

			const GroupId id_;
			CaseId caseId_;

			std::set<Firing> anchorFirings_;
			std::set<Firing> regularFirings_;
			std::vector<Link> links_;
		};
	}
}