#include "PmergeMe.hpp"

/*
** Vector Operations
*/
void PmergeMe::printVec(const std::string &state)
{
	std::cout << "Vector[" << _vector.size() << "] " << state << ": ";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

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

int PmergeMe::generateJacobstahlSequenceVec(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return (1);
	return (generateJacobstahlSequenceVec(index - 1) + 2 * generateJacobstahlSequenceVec(index - 2));
}

void PmergeMe::fillJacobstahlSequenceVec(void)
{
	_jacobSequenceVec.push_back(0);
	_jacobSequenceVec.push_back(1);
	for (int i = 2; i < THRESHOLD; ++i)
	{
		_jacobSequenceVec.push_back(generateJacobstahlSequenceVec(i));
	}
}

bool PmergeMe::isNumberInJacobSequenceVec(int number)
{
	for (std::vector<int>::iterator it = _jacobSequenceVec.begin(); it != _jacobSequenceVec.end(); ++it)
	{
		if (number == *it)
			return true;
	}
	return false;
}

void PmergeMe::combinateJacobVec(void)
{
	for (int index = 3; index < THRESHOLD; index++)
	{
		int value = _jacobSequenceVec[index];
		_combinatorVec.push_back(value);
		value--;

		while (!isNumberInJacobSequenceVec(value))
		{
			_combinatorVec.push_back(value);
			value--;
		}
	}
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
	for (std::vector<int>::iterator it = _combinatorVec.begin(); it != _combinatorVec.end(); ++it)
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

void PmergeMe::checkArgs(int argc, char const *argv[])
{
	std::string str;
	for (int i = 0; i < argc; ++i)
	{
		str = argv[i];
		if (str[0] == '+')
		{
			str.erase(0, 1);	
		}
		for (int i = 0; i < static_cast<int>(str.size()); ++i)
		{
			if (!std::isdigit(str[i]))
				throw std::runtime_error("Error");
		}
		if (std::atof(str.c_str()) > std::numeric_limits<int>::max())
			throw std::runtime_error("Error");
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

void PmergeMe::printTimeExecutionVec(void)
{
	double executionTimeMs = (static_cast<double>(_endTimeVec - _startTimeVec) / CLOCKS_PER_SEC * 1000000.0);
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << executionTimeMs << "ms" << std::endl;
}