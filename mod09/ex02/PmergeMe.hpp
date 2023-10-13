#ifndef EX02_PMERGEME_HPP
#define EX02_PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>
#include <cstdlib>

#define SHOW_DEFAULT_MESSAGES	0

class PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe&operator=(const PmergeMe &copy);

		void pMergeMeAlgorithm(int const argc, char const *argv[]);
		void checkArgs(std::string &str);
		void compareAndSwap(int &a, int &b);
		void printVector(void);

		void determineTheLarger(void);
		void insertionSort(void);

	private:
		std::list<int> _list;
		std::vector<int> _vector;

};

#endif // EX02_PMERGEME_HPP