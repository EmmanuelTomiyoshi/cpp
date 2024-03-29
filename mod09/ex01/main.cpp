#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error. Usage: ./RPN <math expression>" << std::endl;
		return 1;
	}

	RPN rpn;

	try
	{
		rpn.evaluate(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}