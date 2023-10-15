#ifndef EX02_PMERGEME_HPP
#define EX02_PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <limits>
#include <cstdlib>
#include <time.h>

#define SHOW_DEFAULT_MESSAGES	0
#define THRESHOLD				12

typedef std::vector<std::pair<int, int> >	__pairVector;
typedef __pairVector::iterator				__vecIterator;

typedef std::deque<std::pair<int, int> >	__pairDeque;
typedef __pairDeque::iterator				__deqIterator;

class PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe&operator=(const PmergeMe &copy);

		void	pMergeMeAlgorithm(int argc, char const *argv[]);
		void	printContainer(const std::string &state) const;
		void	checkArgs(int argc, char const *argv[]);
		void	fillContainers(int argc, char const *argv[]);
		void	fillPairs(int argc, char const *argv[]);
		void	fillJacobstahlSequence(void);
		bool	isNumberInJacobSequence(int number);
		int		generateJacobstahlSequence(int n);
		void	combinateJacob(void);
		void	sortVector(void);
		void	sortDeque(void);

		//vector functions
		void	fillPairVec(int argc, char const *argv[]);
		void	swapLargerValueVec(void);
		void	mergeSortVec(int begin, int end);
		void	mergeVec(int begin, int middle, int end);
		void	pendVec(void);
		int		binarySearchVec(int find);
		void	pushPendVec(void);
		void	updateVec(void);

		//vector functions
		void	fillPairDeq(int argc, char const *argv[]);
		void	swapLargerValueDeq(void);
		void	mergeSortDeq(int begin, int end);
		void	mergeDeq(int begin, int middle, int end);
		void	pendDeq(void);
		int		binarySearchDeq(int find);
		void	pushPendDeq(void);
		void	updateDeq(void);

		//templates

		template <typename T>
		void printTimeExecution(T container, const std::string &type, clock_t _endTime, clock_t _startTime)
		{
			double executionTimeMs = (static_cast<double>(_endTime - _startTime) / CLOCKS_PER_SEC * 1000.0);
			std::cout << "Time to process a range of " << container.size() << " elements with std::"
			<< type << ": " << executionTimeMs << "ms" << std::endl;
		}

	private:
		int									_struggler;
		bool								_hasStruggler;
		std::vector<int>					_jacobSequence;
		std::vector<int>					_combinator;

		//vector
		__pairVector						_pairVec;
		std::vector<int>					_vector;
		std::vector<int>					_mainChainVec;
		std::vector<int>					_pendVec;
		clock_t								_startTimeVec;
		clock_t								_endTimeVec;

		//list
		__pairDeque							_pairDeq;
		std::deque<int>						_deque;
		std::deque<int>						_mainChainDeq;
		std::deque<int>						_pendDeq;
		clock_t								_startTimeDeq;
		clock_t								_endTimeDeq;

};

#endif // EX02_PMERGEME_HPP