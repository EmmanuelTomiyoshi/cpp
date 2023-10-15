#ifndef EX02_PMERGEME_HPP
#define EX02_PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>
#include <cstdlib>
#include <time.h>

#define SHOW_DEFAULT_MESSAGES	0
#define THRESHOLD				12

typedef std::vector<std::pair<int, int> >	__pairVector;
typedef __pairVector::iterator				__vecIterator;
typedef std::list<std::pair<int, int> >		__pairList;
typedef __pairList::iterator				__listIterator;

class PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe&operator=(const PmergeMe &copy);

		void	pMergeMeAlgorithm(int argc, char const *argv[]);
		void	checkArgs(int argc, char const *argv[]);
		void	fillContainers(int argc, char const *argv[]);
		void	fillPairs(int argc, char const *argv[]);
		void	sortVector();


		void	printVec(const std::string &state);
		void	fillPairVec(int argc, char const *argv[]);
		void	swapLargerValueVec(void);
		void	mergeSortVec(int begin, int end);
		void	mergeVec(int begin, int middle, int end);
		void	pendVec(void);
		void	fillJacobstahlSequenceVec(void);
		int		generateJacobstahlSequenceVec(int n);
		bool	isNumberInJacobSequenceVec(int number);
		void	combinateJacobVec(void);
		int		binarySearchVec(int find);
		void	pushPendVec(void);
		void	updateVec(void);
		void	printTimeExecutionVec(void);


	private:
		int									_struggler;
		bool								_hasStruggler;

		//vector
		__pairVector						_pairVec;
		std::vector<int>					_vector;
		std::vector<int>					_mainChainVec;
		std::vector<int>					_pendVec;
		std::vector<int>					_jacobSequenceVec;
		std::vector<int>					_combinatorVec;
		clock_t								_startTimeVec;
		clock_t								_endTimeVec;

		//list
		__pairList							_pairLst;
		std::list<int>						_list;
		std::list<int>						_mainChainLst;
		std::list<int>						_pendLst;
		std::list<int>						_jacobSequenceLst;
		std::list<int>						_combinatorLst;
		int									_strugglerLst;
		bool								_hasStrugglerLst;
		clock_t								_startTimeLst;
		clock_t								_endTimeLst;

};

#endif // EX02_PMERGEME_HPP