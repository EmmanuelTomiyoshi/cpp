#include "ScalarConverter.hpp"

#include <cstdlib>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc > 2)
			std::cerr << "Error: too many arguments" << std::endl;
		else
			std::cerr << "Error: missing data. Usage: ./scalarConverter [data]" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
}



