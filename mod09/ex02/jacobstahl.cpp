#include "PmergeMe.hpp"

bool PmergeMe::isNumberInJacobSequence(int number)
{
	for (std::vector<int>::iterator it = _jacobSequence.begin(); it != _jacobSequence.end(); ++it)
	{
		if (number == *it)
			return true;
	}
	return false;
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

int PmergeMe::generateJacobstahlSequence(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return (1);
	return (generateJacobstahlSequence(index - 1) + 2 * generateJacobstahlSequence(index - 2));
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
