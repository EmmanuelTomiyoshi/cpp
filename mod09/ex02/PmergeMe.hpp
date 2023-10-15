#ifndef EX02_PMERGEME_HPP
#define EX02_PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>
#include <cstdlib>

#define SHOW_DEFAULT_MESSAGES	0
#define THRESHOLD				20

class PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe&operator=(const PmergeMe &copy);

		void pMergeMeAlgorithm(int argc, char const *argv[]);
		void checkArgs(std::string &str);
		void printVector(void);

		void swapLargerValue(void);
		void insertionSort(void);

		typedef std::vector<std::pair<int, int> >	__pairVector;
		typedef __pairVector::iterator				__vecIterator;

		void merge(int begin, int middle, int end);
		void mergeSort(int begin, int end);
		void pend(void);

		int		generateJacobsthalSequence(int n);
		void	fillJacobsthalSequence(void);

		void	combinateJacob(void);
		bool	isNumberInJacobSequence(int number);
		void	pushPend(void);

		int		binarySearch(int find);


	private:
		__pairVector						_vector;
		std::vector<int>					_mainChain;
		std::vector<int>					_pend;
		std::vector<int>					_jacobSequence;
		std::vector<int>					_combinator;

		std::list<int> 						_list;
		int									_struggler;

};

#endif // EX02_PMERGEME_HPP