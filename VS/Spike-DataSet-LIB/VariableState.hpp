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
#include <set>
#include <map>
#include <iterator>

#include "DataSetTypes.hpp"
#include "Variable.hpp"

namespace spike
{
	namespace dataset
	{
		class VariableState
		{
		public:
			VariableState() = default;						// simple constructor

			VariableState(const VariableState& other) = default;	// copy constructor
			VariableState(VariableState&& other) = delete;		// move constructor
			VariableState& operator=(const VariableState& rhs) = default; // copy assignment operator
			VariableState& operator=(VariableState&& rhs) = delete;		// move assignment operator

			void setVariableValue(const VariableId variableId, const Variable::PropertyName propertyName, const std::string& propertyValue)
			{
				if (this->hasVariableId(variableId))
				{
					//		std::cout << " VariableState::setVariableValue() updating existing variableId " << variableId << std::endl;
					this->variables_.at(variableId).setVariableValue(propertyName, propertyValue);
				}
				else
				{
					//		std::cout << " VariableState::setVariableValue() inserting new variableId " << variableId << std::endl;
					this->createVariableId(variableId, propertyName, propertyValue);
				}
			}

			const std::string getVariableValue(const VariableId variableId, const Variable::PropertyName propertyName) const
			{
				if (this->hasVariableId(variableId))
				{
					return this->variables_.at(variableId).getVariableValue(propertyName);
				}
				throw std::runtime_error("variableId not present");
			}

			bool hasVariableValue(const VariableId variableId, const Variable::PropertyName propertyName) const
			{
				if (this->hasVariableId(variableId))
				{
					return this->variables_.at(variableId).hasVariableValue(propertyName);
				}
				throw std::runtime_error("variableId not present");
			}

			unsigned int getNumberOfVariables() const
			{
				return static_cast<unsigned int>(this->variables_.size());
			}

			const std::set<VariableId> getVariableIds() const
			{
				//Speed consideration: create a member field with the returning set instead of creating it on the fly
				std::set<VariableId> s;
				for (std::map<VariableId, Variable>::const_iterator it = this->variables_.begin(); it != this->variables_.end(); ++it)
				{
					s.insert(it->first);
				}
				return s;
			}

			bool hasVariableId(const VariableId variableId) const
			{
				return (this->variables_.find(variableId) != this->variables_.end());
			}


			std::string toString() const
			{
				std::ostringstream oss;
				const std::set<VariableId> variableIds = this->getVariableIds();

				oss << "----------------";
				for (int i = 0; i < static_cast<int>(variableIds.size()); i++)
				{
					oss << "--------";
				}

				oss << std::endl << "variableId:\t";
				for (const VariableId& variableId : variableIds)
				{
					oss << variableId << "\t";
				}

				oss << std::endl << "Used:\t\t";
				for (const VariableId& variableId : variableIds)
				{
					oss << this->getVariableValue(variableId, Variable::PropertyName::Used) << "\t";
				}

				oss << std::endl << "Description:\t";
				for (const VariableId& variableId : variableIds)
				{
					oss << this->getVariableValue(variableId, Variable::PropertyName::Description) << "\t";
				}

				oss << std::endl << "VariableType:\t";
				for (const VariableId& variableId : variableIds)
				{
					oss << this->getVariableValue(variableId, Variable::PropertyName::VariableType) << "\t";
				}

				oss << std::endl << "VariableGroup:\t";
				for (const VariableId& variableId : variableIds)
				{
					oss << this->getVariableValue(variableId, Variable::PropertyName::VariableGroup) << "\t";
				}

				oss << std::endl;
				return oss.str();
			}


		protected:

			virtual ~VariableState() = default;

		private:

			std::map<VariableId, Variable> variables_;

			void createVariableId(const VariableId variableId, const Variable::PropertyName propertyName, const std::string& propertyValue)
			{
				Variable variableTmp;
				variableTmp.setVariableValue(propertyName, propertyValue);
				// tell make_pair that variableTmp is indeed temporary (with move) such that make_pair can use swap semantics
				this->variables_.insert(std::make_pair(variableId, std::move(variableTmp)));
			}
		};
	}
}