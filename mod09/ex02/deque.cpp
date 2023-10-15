#include "PmergeMe.hpp"

/*
** Deque Operations
*/

void PmergeMe::swapLargerValueDeq(void)
{
	for (__deqIterator it = _pairDeq.begin(); it != _pairDeq.end(); ++it)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::mergeDeq(int begin, int middle, int end)
{

	__pairDeque	firstSub(_pairDeq.begin() + begin, _pairDeq.begin() + middle + 1);
	__pairDeque	secondSub(_pairDeq.begin() + middle + 1, _pairDeq.begin() + end + 1);

	int left = 0, right = 0;
	int top = begin;

    while (left < static_cast<int>(firstSub.size()) && right < static_cast<int>(secondSub.size()))
	{
		if (firstSub[left] <= secondSub[right])
		{
			_pairDeq[top] = firstSub[left];
			left++;
		}
		else
		{
            _pairDeq[top] = secondSub[right];
            right++;
        }
        top++;
    }

    while (left < static_cast<int>(firstSub.size()))
	{
        _pairDeq[top] = firstSub[left];
        left++;
        top++;
    }

    while (right < static_cast<int>(secondSub.size()))
	{
        _pairDeq[top] = secondSub[right];
        right++;
        top++;
    }
}

//divides the Deque into two subDeques, sort them and merge them
void PmergeMe::mergeSortDeq(int begin, int end)
{
	if (begin < end)
	{
		//middle is the point where the Deque is divided into two subarrays
		int middle = begin + (end - begin) / 2;

		mergeSortDeq(begin, middle);
		mergeSortDeq(middle + 1, end);

		mergeDeq(begin, middle, end);
	}
}

void PmergeMe::pendDeq(void)
{
	for (__deqIterator it = _pairDeq.begin(); it != _pairDeq.end(); ++it)
	{
		_mainChainDeq.push_back(it->first);
		_pendDeq.push_back(it->second);
	}

	_mainChainDeq.insert(_mainChainDeq.begin(), *_pendDeq.begin());
}

int PmergeMe::binarySearchDeq(int find)
{
	int left, right, middle;
	left = 0;
	right = _mainChainDeq.size() - 1;
	while (left <= right)
	{
		middle = left + (right - left) / 2;

		if (_mainChainDeq[middle] == find)
			return middle;

		if (find > _mainChainDeq[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return left;
}

void PmergeMe::pushPendDeq(void)
{
	for (std::vector<int>::iterator it = _combinator.begin(); it != _combinator.end(); ++it)
	{
		int keep = *(it) - 1;
		if (keep < static_cast<int>(_pendDeq.size()))
		{
			std::deque<int>::iterator find = _mainChainDeq.begin() + binarySearchDeq(_pendDeq[keep]);
			_mainChainDeq.insert(find, _pendDeq[keep]);
		}
	}

	//add struggler
	if (_hasStruggler)
	{
		std::deque<int>::iterator find = _mainChainDeq.begin() + binarySearchDeq(_struggler);
		_mainChainDeq.insert(find, _struggler);
	}
}

void PmergeMe::updateDeq(void)
{
	_deque.clear();

	for (std::deque<int>::iterator it = _mainChainDeq.begin(); it != _mainChainDeq.end(); it++)
	{
		_deque.push_back(*it);
	}
}
