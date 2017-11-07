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
#include <map>

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"

namespace spike
{
	namespace v1
	{

		class SampleScore2
		{
		public:
			~SampleScore2() = default;

			SampleScore2() = default;

			SampleScore2(const std::set<CaseId>& caseIds, const std::set<GroupId>& groupIds)
				: caseIds_(caseIds)
				, groupIds_(groupIds)
				, nCases_(static_cast<unsigned int>(caseIds.size()))
				, nGroups_(static_cast<unsigned int>(groupIds.size()))
			{
				//	std::cout << "SampleScore::ctor" << std::endl;
				this->occuranceCount_.resize(this->nCases_ * this->nGroups_);
				this->sampleCount_.resize(this->nCases_);
				this->clear();
			}

			SampleScore2(const SampleScore2& other) // copy constructor
				: caseIds_(other.caseIds_)
				, nCases_(other.nCases_)
				, occuranceCount_(other.occuranceCount_)
				, sampleCount_(other.sampleCount_)
			{
				std::cout << "SampleScore::copy ctor" << std::endl;
			}

			SampleScore2(SampleScore2&& other) // move constructor
				: caseIds_(other.caseIds_)
				, nCases_(other.nCases_)
				, occuranceCount_(std::move(other.occuranceCount_))
				, sampleCount_(std::move(other.sampleCount_))
			{
				//std::cout << "SampleScore::move ctor" << std::endl;
			}

			SampleScore2& operator=(const SampleScore2& other) // copy assignment operator
			{
				std::cout << "SampleScore::copy assignment" << std::endl;
				if (this != &other) // protect against invalid self-assignment
				{
					this->caseIds_ = other.caseIds_;
					this->nCases_ = other.nCases_;
					this->occuranceCount_ = other.occuranceCount_;
					this->sampleCount_ = other.sampleCount_;
				}
				else
				{
					std::cout << "SampleScore::operator=: prevented self-assignment" << std::endl;
				}
				return *this;	// by convention, always return *this
			}

			SampleScore2& operator=(SampleScore2&& other) // move assignment operator
			{
				std::cout << "SampleScore::move assignment" << std::endl;
				assert(this != &other);

				this->caseIds_ = other.caseIds_;
				this->nCases_ = other.nCases_;
				this->occuranceCount_ = std::move(other.occuranceCount_);
				this->sampleCount_ = std::move(other.sampleCount_);

				return *this;	// by convention, always return *this
			}

			void clear()
			{
				this->occuranceCount_.clear();
				this->sampleCount_.clear();
			}

			void add(const CaseId caseId, const GroupId groupId)
			{
				this->groupOrigin_.insert(std::make_pair(groupId, caseId));
			}

			void add(const GroupId groupId, const CaseId caseIdOut)
			{
				this->occuranceCount_[this->index(groupId, caseIdOut)]++;
			}

			void incSampleCount(const CaseId caseId)
			{
				this->sampleCount_[caseId.val]++;
			}

			double getRecall(const CaseId /*caseId*/) const
			{
				return 0;
			}

			double getAccuracy(const CaseId /*caseId*/) const
			{
				return 0;
			}

			double getPerformance() const
			{
				return 0;
			}

			std::string toString() const
			{
				std::ostringstream oss;

				oss << "recall: ";
				for (const CaseId& caseId : this->caseIds_)
				{
					oss << "(case " << caseId << "=" << this->getRecall(caseId) << ")";
				}
				oss << std::endl;

				oss << "accuracy: ";
				for (const CaseId& caseId : this->caseIds_)
				{
					oss << "(case " << caseId << "=" << this->getAccuracy(caseId) << ")";
				}
				oss << std::endl;

				oss << "sampleCount: ";
				for (const CaseId& caseId : this->caseIds_)
				{
					oss << "(case " << caseId << "=" << this->sampleCount_[caseId.val] << ")";
				}
				oss << std::endl;

				oss << "performance = " << this->getPerformance() << std::endl;
				oss << "data = " << std::endl;

				for (const CaseId& caseId1 : this->caseIds_)
				{
					for (const CaseId& caseId2 : this->caseIds_)
					{
						const unsigned int i = this->index(static_cast<GroupId>(caseId1.val), caseId2);
						oss << this->occuranceCount_[i] << "\t";
					}
					oss << std::endl;
				}

				return oss.str();
			}

		private:
			unsigned int nCases_;
			unsigned int nGroups_;
			std::set<CaseId> caseIds_;
			std::set<GroupId> groupIds_;

			std::map<GroupId, CaseId> groupOrigin_;
			std::vector<unsigned int> occuranceCount_;
			std::vector<unsigned int> sampleCount_;

			unsigned int index(const GroupId groupId, const CaseId caseId) const
			{
				return (groupId*this->nCases_) + caseId.val;
			}
		};
	}
}