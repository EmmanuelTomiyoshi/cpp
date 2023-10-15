#include "PmergeMe.hpp"

/*
** Vector Operations
*/

void PmergeMe::swapLargerValueVec(void)
{
	for (__vecIterator it = _pairVec.begin(); it != _pairVec.end(); ++it)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::mergeVec(int begin, int middle, int end)
{

	__pairVector	firstSub(_pairVec.begin() + begin, _pairVec.begin() + middle + 1);
	__pairVector	secondSub(_pairVec.begin() + middle + 1, _pairVec.begin() + end + 1);

	int left = 0, right = 0;
	int top = begin;

    while (left < static_cast<int>(firstSub.size()) && right < static_cast<int>(secondSub.size()))
	{
		if (firstSub[left] <= secondSub[right])
		{
			_pairVec[top] = firstSub[left];
			left++;
		}
		else
		{
            _pairVec[top] = secondSub[right];
            right++;
        }
        top++;
    }

    while (left < static_cast<int>(firstSub.size()))
	{
        _pairVec[top] = firstSub[left];
        left++;
        top++;
    }

    while (right < static_cast<int>(secondSub.size()))
	{
        _pairVec[top] = secondSub[right];
        right++;
        top++;
    }
}

//divides the vector into two subvectors, sort them and merge them
void PmergeMe::mergeSortVec(int begin, int end)
{
	if (begin < end)
	{
		//middle is the point where the vector is divided into two subarrays
		int middle = begin + (end - begin) / 2;

		mergeSortVec(begin, middle);
		mergeSortVec(middle + 1, end);

		mergeVec(begin, middle, end);
	}
}

void PmergeMe::pendVec(void)
{
	for (__vecIterator it = _pairVec.begin(); it != _pairVec.end(); ++it)
	{
		_mainChainVec.push_back(it->first);
		_pendVec.push_back(it->second);
	}

	_mainChainVec.insert(_mainChainVec.begin(), *_pendVec.begin());
}

int PmergeMe::binarySearchVec(int find)
{
	int left, right, middle;
	left = 0;
	right = _mainChainVec.size() - 1;
	while (left <= right)
	{
		middle = left + (right - left) / 2;

		if (_mainChainVec[middle] == find)
			return middle;

		if (find > _mainChainVec[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return left;
}

void PmergeMe::pushPendVec(void)
{
	for (std::vector<int>::iterator it = _combinator.begin(); it != _combinator.end(); ++it)
	{
		int keep = *(it) - 1;
		if (keep < static_cast<int>(_pendVec.size()))
		{
			std::vector<int>::iterator find = _mainChainVec.begin() + binarySearchVec(_pendVec[keep]);
			_mainChainVec.insert(find, _pendVec[keep]);
		}
	}

	//add struggler
	if (_hasStruggler)
	{
		std::vector<int>::iterator find = _mainChainVec.begin() + binarySearchVec(_struggler);
		_mainChainVec.insert(find, _struggler);
	}
}

void PmergeMe::updateVec(void)
{
	_vector.clear();

	for (std::vector<int>::iterator it = _mainChainVec.begin(); it != _mainChainVec.end(); it++)
	{
		_vector.push_back(*it);
	}
}
