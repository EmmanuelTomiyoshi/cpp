#include "PmergeMe.hpp"

//list
//vector

int main(int const argc, char const *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error. Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}

	PmergeMe pm;


	try
	{
		pm.pMergeMeAlgorithm(argc - 1, argv + 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}