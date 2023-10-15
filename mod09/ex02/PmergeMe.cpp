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

void PmergeMe::sortVector(void)
{
	_startTimeVec = clock();

	printVec("Before");

	swapLargerValueVec();
	mergeSortVec(0, _pairVec.size() - 1);
	pendVec();
	fillJacobstahlSequenceVec();
	combinateJacobVec();
	pushPendVec();
	updateVec();

	_endTimeVec = clock();
	printVec("After");
	printTimeExecutionVec();
}

void PmergeMe::fillContainers(int argc, char const *argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		_vector.push_back(std::atof(argv[i]));
		_list.push_back(std::atof(argv[i]));
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
		_pairLst.push_back(std::make_pair(first, second));
	}
}

void PmergeMe::pMergeMeAlgorithm(int argc, char const *argv[])
{
	checkArgs(argc, argv);
	fillContainers(argc, argv);
	fillPairs(argc, argv);
	sortVector();
}