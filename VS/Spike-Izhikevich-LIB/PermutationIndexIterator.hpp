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

#include <vector>
#include <string>
#include <iostream> // for cerr and cout

class PermutationIndexIterator
{
public:

	// constructor
	PermutationIndexIterator()
		: nElements_(0)
		, selectionSize_(0)
	{
		this->setToEnd();
	}

	// constructor
	PermutationIndexIterator(const unsigned int nElements, const unsigned int selectionSize)
		: nElements_(nElements)
		, selectionSize_(selectionSize)
	{
		//std::cout << "PermutationIndexIterator::ctor: nElements = " << this->_nElements << "; selectionSize=" << this->_selectionSize << std::endl;
		if (this->nElements_ < this->selectionSize_) {
			//log.warn("LennySimpleIterator: order " + order + " is too high, assuming order " + (elements.length) + ".");
			this->nElements_ = this->selectionSize_;
		}
		this->indices_.resize(this->selectionSize_);
		this->setToBegin();
	}

	// copy constructor
	PermutationIndexIterator(const PermutationIndexIterator& rhs)
		: indices_(rhs.indices_)
		, nElements_(rhs.nElements_)
		, selectionSize_(rhs.selectionSize_)
		, atEnd_(rhs.atEnd_)
	{
		std::cout << "PermutationIndexIterator::copy ctor" << std::endl;
	}

	// move constructor
	PermutationIndexIterator(PermutationIndexIterator&& rhs)
		: indices_(std::move(rhs.indices_))
		, nElements_(std::move(rhs.nElements_))
		, selectionSize_(std::move(rhs.selectionSize_))
		, atEnd_(std::move(rhs.atEnd_))
	{
		std::cout << "PermutationIndexIterator::move ctor " << std::endl;
	}

	// copy assignment
	PermutationIndexIterator& operator= (const PermutationIndexIterator& rhs)
	{
		std::cout << "PermutationIndexIterator::copy assignment" << std::endl;
		this->nElements_ = rhs.nElements_;
		this->selectionSize_ = rhs.selectionSize_;
		this->indices_ = rhs.indices_;
		this->atEnd_ = rhs.atEnd_;
		return *this;	// by convention, always return *this
	}

	// move assignment
	PermutationIndexIterator& operator= (PermutationIndexIterator&& rhs)
	{
		std::cout << "LennySimpleIterator::move assignment" << std::endl;
		this->nElements_ = std::move(rhs.nElements_);
		this->selectionSize_ = std::move(rhs.selectionSize_);
		this->indices_ = std::move(rhs.indices_);
		this->atEnd_ = std::move(rhs.atEnd_);
		return *this;	// by convention, always return *this
	}

	// equality comparison
	bool operator== (const PermutationIndexIterator& rhs) const
	{
		if (this->atEnd_) {
			if (rhs.atEnd_) {
				return true;
			}
			return false;
		} else {
			if (rhs.atEnd_) {
				return false;
			}
			return (this->indices_ == rhs.indices_);
		}
	}

	// inequality comparison
	bool operator!= (const PermutationIndexIterator& rhs) const
	{
		if (this->atEnd_) {
			if (rhs.atEnd_) {
				return false;
			}
			return true;
		} else {
			if (rhs.atEnd_) {
				return true;
			}
			return (this->indices_ != rhs.indices_);
		}
	}

	// dereferencing
	const std::vector<unsigned int>& operator* () const
	{
		return this->indices_;
	}

	//////////////////////////////////////////////////////////////////////
	// nextPermutation returns true if next permutation is set to the provided array; false if no next permutation exists.
	__inline bool nextPermutation(std::vector<unsigned int>& indices, const unsigned int nIndices, const unsigned int maxIndex)
	{
		unsigned int i = 1;
		while (++indices[nIndices - i] > (maxIndex - i)) {
			if (++i > nIndices) {
				return false; // no next permutation exists
			}
		}
		while (i > 1) {
			indices[nIndices - i + 1] = indices[nIndices - i] + 1;
			i--;
		}
		return true;
	}

	// increment operator
	void operator++ ()
	{
		if (!nextPermutation(this->indices_, this->selectionSize_, this->nElements_)) {
			this->atEnd_ = true;
		}
	}

	void setToEnd()
	{
		this->atEnd_ = true;
	}

	void setToBegin()
	{
		this->atEnd_ = false;
		for (unsigned int i = 0; i<this->selectionSize_; ++i) {
			this->indices_[i] = i;
		}
	}

	std::string toString() const
	{
		std::ostringstream oss;
		for (unsigned int i = 0; i < this->selectionSize_; ++i) {
			oss << this->indices_[i] << ", ";
		}
		return oss.str();
	}

private:

	std::vector<unsigned int> indices_;
	unsigned int nElements_;
	unsigned int selectionSize_;

	bool atEnd_;
};