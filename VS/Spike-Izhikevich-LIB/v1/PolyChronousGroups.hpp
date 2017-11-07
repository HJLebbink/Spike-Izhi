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
#include <memory>
#include <map>

#include "../../Spike-Izhikevich-LIB/v1/PolyChronousGroup.hpp"
#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"

namespace spike
{
	namespace v1
	{


		class PolyChronousGroups
		{
		public:
			// destructor
			~PolyChronousGroups() = default;

			// constructor
			PolyChronousGroups()
				: nGroups_(0)
			{
			}

			const std::shared_ptr<const PolyChronousGroup> getGroup(const GroupId groupId) const
			{
				if (groupId < this->nGroups_)
				{
					const std::shared_ptr<const PolyChronousGroup> group = this->data_.at(groupId);
					#if _DEBUG
					if (group->getGroupId() != groupId)
					{
						std::cerr << "PolyChronousGroups::getGroup(); ERROR: groupId=" << groupId << "; groupId=" << group->getGroupId() << std::endl;
						throw 1;
					}
					#endif
					return group;
				}
				else
				{
					std::cerr << "PolyChronousGroups::getGroup() WARNING: provided groupId " << groupId << " does not exist" << std::endl;
					return nullptr;
				}
			}

			Ms getLongestLength() const
			{
				Ms longestLength = 0;
				for (auto iter = this->data_.cbegin(); iter != this->data_.cend(); ++iter)
				{
					const Ms length = iter->second->getLastFiringTime();
					if (length > longestLength)
					{
						longestLength = length;
					}
				}
				return longestLength;
			}

			void add(const std::shared_ptr<PolyChronousGroup>& group)
			{
				const std::set<Firing> anchors = group->getAnchorFirings();

				for (auto iter = this->data_.cbegin(); iter != this->data_.cend(); ++iter)
				{
					const auto group2 = iter->second;
					if (isSubSet<Firing>(anchors, group2->getAnchorFirings()))
					{
						std::cout << "PolyChronousGroups::add_private(): group " << group->getGroupId() << " is subsumed under group " << group2->getGroupId() << std::endl;
					}
				}

				this->data_.insert(std::make_pair(group->getGroupId(), group));
				this->nGroups_++;
			}

			const std::vector<GroupId> getSubsumedGroupIds(const std::shared_ptr<const PolyChronousGroup>& /*group*/) const
			{
				std::vector<GroupId> groupIds;
				//TODO
				return groupIds;
			}

			const std::vector<GroupId> getGroupIds() const
			{
				std::vector<GroupId> groupIds;
				groupIds.reserve(this->data_.size());
				for (auto iter = this->data_.cbegin(); iter != this->data_.cend(); ++iter)
				{
					groupIds.push_back(iter->first);
				}
				return groupIds;
			}

			//Load all polychronous groups with the provided filename from the provided directory
			void loadFromFile(const std::string& filename)
			{
				//1] cleanup old group data;
				this->data_.clear();
				this->nGroups_ = 0;

				//2] load new group data;
				for (unsigned int i = 0; i < 5000; i++)
				{

					std::stringstream fullFilenameStream;
					fullFilenameStream << filename << "." << i << ".txt";
					const std::string fullFilename = fullFilenameStream.str();

					std::ifstream file(fullFilename);
					if (file.good())
					{
						file.close(); // just to check whether the file exists

						const GroupId groupId = static_cast<GroupId>(this->nGroups_);
						auto newGroup = std::make_shared<PolyChronousGroup>(groupId);
						newGroup->loadFromFile(filename);
						this->data_.insert(std::make_pair(groupId, std::move(newGroup)));
						this->nGroups_++;
					}
				}
			}

			void saveToFile(const std::string& filename) const
			{
				for (auto iter = this->data_.cbegin(); iter != this->data_.cend(); ++iter)
				{
					const auto group = iter->second;
					group->saveToFile(filename);
				}
			}

			std::string getOverview() const
			{
				std::ostringstream oss;
				oss << "PolyChronousGroups: " << this->nGroups_ << " groups" << std::endl;

				for (auto iter = this->data_.cbegin(); iter != this->data_.cend(); ++iter)
				{
					auto group = iter->second;
					oss << "groupId=" << group->getGroupId() << "; caseId=" << group->getCaseId() << "; nAnchors=" << group->getNumberOfAnchorFirings() << std::endl;
				}
				return oss.str();
			}

			//std::string toString() const;

		private:

			unsigned int nGroups_;
			std::map<GroupId, std::shared_ptr<PolyChronousGroup>> data_;

			template <typename T>
			static bool isSubSet(
				const std::set<T>& superSet,
				const std::set<T>& subSet)
			{
				if (superSet.size() < subSet.size())
				{
					return false;
				}

				const auto end = superSet.cend();
				for (const T& e : subSet)
				{
					bool found = false;
					for (auto it = superSet.cbegin(); ((it != end) && (!found)); ++it)
					{
						if (*it == e)
						{
							found = true;
						}
					}
					if (!found)
					{
						return false;
					}
				}
				return true;
			}
		};
	}
}