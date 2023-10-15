#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _hasStruggler(false)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PmergeMe] constructor called" << std::endl;
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _hasStruggler(false)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PmergeMe] copy constructor called" << std::endl;
	}
	*this = copy;
}

PmergeMe&PmergeMe::operator=(const PmergeMe &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PmergeMe] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{

	}
	return *this;
}

PmergeMe::~PmergeMe(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PmergeMe] destructor called" << std::endl;
	}
}

void PmergeMe::checkArgs(std::string &str)
{
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

void PmergeMe::printVector(void)
{
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::swapLargerValue(void)
{
	for (__vecIterator it = _pairVector.begin(); it != _pairVector.end(); ++it)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::merge(int begin, int middle, int end)
{

	__pairVector	firstSub(_pairVector.begin() + begin, _pairVector.begin() + middle + 1);
	__pairVector	secondSub(_pairVector.begin() + middle + 1, _pairVector.begin() + end + 1);

	int left = 0, right = 0;
	int top = begin;

    while (left < static_cast<int>(firstSub.size()) && right < static_cast<int>(secondSub.size()))
	{
		if (firstSub[left] <= secondSub[right])
		{
			_pairVector[top] = firstSub[left];
			left++;
		}
		else
		{
            _pairVector[top] = secondSub[right];
            right++;
        }
        top++;
    }

    while (left < static_cast<int>(firstSub.size()))
	{
        _pairVector[top] = firstSub[left];
        left++;
        top++;
    }

    while (right < static_cast<int>(secondSub.size()))
	{
        _pairVector[top] = secondSub[right];
        right++;
        top++;
    }
}

//divides the vector into two subvectors, sort them and merge them
void PmergeMe::mergeSort(int begin, int end)
{
	if (begin < end)
	{
		//middle is the point where the vector is divided into two subarrays
		int middle = begin + (end - begin) / 2;

		mergeSort(begin, middle);
		mergeSort(middle + 1, end);

		merge(begin, middle, end);
	}
}

void PmergeMe::pend(void)
{
	for (__vecIterator it = _pairVector.begin(); it != _pairVector.end(); ++it)
	{
		_mainChain.push_back(it->first);
		_pend.push_back(it->second);
	}

	_mainChain.insert(_mainChain.begin(), *_pend.begin());

	// for (std::vector<int>::iterator it = _mainChain.begin(); it != _mainChain.end(); ++it)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

}

int PmergeMe::generateJacobstahlSequence(int index)
{

	if (index == 0)
		return 0;
	if (index == 1)
		return (1);
	return (this->generateJacobstahlSequence(index - 1) + 2 * this->generateJacobstahlSequence(index - 2));

	//0 1 1 3 5 11 21
}

void PmergeMe::fillJacobstahlSequence(void)
{
	_jacobSequence.push_back(0);
	_jacobSequence.push_back(1);
	for (int i = 2; i < THRESHOLD; ++i)
	{
		_jacobSequence.push_back(generateJacobstahlSequence(i));
	}
}

bool PmergeMe::isNumberInJacobSequence(int number)
{
	for (std::vector<int>::iterator it = _jacobSequence.begin(); it != _jacobSequence.end(); ++it)
	{
		if (number == *it)
			return true;
	}
	return false;
}

void PmergeMe::combinateJacob(void)
{
	for (int index = 3; index < THRESHOLD; index++)
	{
		int value = _jacobSequence[index];
		_combinator.push_back(value);
		value--;

		while (!isNumberInJacobSequence(value))
		{
			_combinator.push_back(value);
			value--;
		}
	}
}

int PmergeMe::binarySearch(int find)
{
	int left, right, middle;
	left = 0;
	right = _mainChain.size() - 1;
	while (left <= right)
	{
		middle = left + (right - left) / 2;

		if (_mainChain[middle] == find)
			return middle;

		if (find > _mainChain[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return left;
}

void PmergeMe::pushPend(void)
{
	for (std::vector<int>::iterator it = _combinator.begin(); it != _combinator.end(); ++it)
	{
		int keep = *(it) - 1;
		if (keep < static_cast<int>(_pend.size()))
		{
			std::vector<int>::iterator find = _mainChain.begin() + binarySearch(_pend[keep]);
			_mainChain.insert(find, _pend[keep]);
		}
	}
}

void PmergeMe::pMergeMeAlgorithm(int argc, char const *argv[])
{
	std::string str;

	for (int i = 0; i < argc; ++i)
	{
		str = argv[i];
		checkArgs(str);
		_vector.push_back(std::atof(argv[i]));
	}

	if (argc % 2 != 0)
	{
		_struggler = std::atof(str.c_str());
		argc--;	//make sure we have a even quantity to make pairs
		_hasStruggler = true;
	}

	int first, second = 0;
	for (int i = 0; i < argc; i += 2)
	{
		first = static_cast<int>(std::atof(argv[i]));
		second = static_cast<int>(std::atof(argv[i + 1]));
		_pairVector.push_back(std::make_pair(first, second));
	}

	std::cout << "Size before: " << _vector.size() << std::endl;
	printVector();

	swapLargerValue();
	mergeSort(0, _pairVector.size() - 1);
	pend();
	fillJacobstahlSequence();
	combinateJacob();
	pushPend();

	if (_hasStruggler)
	{
		std::vector<int>::iterator find = _mainChain.begin() + binarySearch(_struggler);
		_mainChain.insert(find, _struggler);
	}

	_vector.clear();

	for (std::vector<int>::iterator it = _mainChain.begin(); it != _mainChain.end(); it++)
	{
		_vector.push_back(*it);
	}

	std::cout << "Size after: " << _vector.size() << std::endl;
	printVector();


}