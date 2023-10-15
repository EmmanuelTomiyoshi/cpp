#include "PmergeMe.hpp"

/*
** Orthodoxical Canonical Form
*/
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
		*this = copy;
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

void PmergeMe::printContainer(const std::string &state) const
{
	std::cout << state << ": ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector(void)
{
	swapLargerValueVec();
	mergeSortVec(0, _pairVec.size() - 1);
	pendVec();
	pushPendVec();
	updateVec();

	_endTimeVec = clock();
}

void PmergeMe::sortDeque(void)
{
	swapLargerValueDeq();
	mergeSortDeq(0, _pairDeq.size() - 1);
	pendDeq();
	pushPendDeq();
	updateDeq();

	_endTimeDeq = clock();
}

void PmergeMe::fillContainers(int argc, char const *argv[])
{
	_startTimeVec = clock();
	_startTimeDeq = clock();
	for (int i = 0; i < argc; ++i)
	{
		_vector.push_back(std::atof(argv[i]));
		_deque.push_back(std::atof(argv[i]));
	}

	if (argc % 2 != 0)
	{
		_struggler = std::atof(argv[argc - 1]);
		_hasStruggler = true;
	}
}

void PmergeMe::fillPairs(int argc, char const *argv[])
{
	if (argc % 2 != 0)
		argc--; //make sure we have a even quantity to make pairs
	int first, second = 0;
	for (int i = 0; i < argc; i += 2)
	{
		first = static_cast<int>(std::atof(argv[i]));
		second = static_cast<int>(std::atof(argv[i + 1]));
		_pairVec.push_back(std::make_pair(first, second));
		_pairDeq.push_back(std::make_pair(first, second));
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
				throw std::runtime_error("Error: value must be a positive integer");
		}
		if (std::atof(str.c_str()) > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: number too large");
	}
}

void PmergeMe::pMergeMeAlgorithm(int argc, char const *argv[])
{
	checkArgs(argc, argv);
	fillContainers(argc, argv);
	fillPairs(argc, argv);

	printContainer("Before");

	fillJacobstahlSequence();
	combinateJacob();

	sortVector();
	sortDeque();
	printContainer("After");

	printTimeExecution(_vector, "vector", _endTimeVec, _startTimeVec);
	printTimeExecution(_deque, "deque", _endTimeDeq, _startTimeDeq);
}