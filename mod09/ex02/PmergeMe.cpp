#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PmergeMe] constructor called" << std::endl;
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy)
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

void PmergeMe::compareAndSwap(int &a, int &b)
{
	if (a < b)
		std::swap(a, b);
}

void PmergeMe::printVector(void)
{
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::determineTheLarger(void)
{
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end();)
	{
		if (it + 1 != _vector.end())
			compareAndSwap(*it, *(it + 1));
		else
			break ;
		it += 2;
	}

}

// void PmergeMe::insertionSort(void)
// {
// 	int i, j, key;

// 	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); )
// 	{
// 		key = _vector.
// 	}

// }

void PmergeMe::pMergeMeAlgorithm(int const argc, char const *argv[])
{
	std::string str;
	for (int i = 0; i < argc; ++i)
	{
		str = argv[i];
		checkArgs(str);
		_vector.push_back(std::atof(str.c_str()));	//push to vector
	}

	bool struggler = _vector.size() % 2 == 0;

	std::cout << "Step 1: " << std::endl;
	printVector();

	determineTheLarger();
	insertionSort(); //I stopped here

	std::cout << "Step 2: " << std::endl;
	printVector();


}