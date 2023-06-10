#include "ScalarConverter.hpp"

#include <cstdlib>
#include <sstream>

int main(int argc, char *argv[])
{	
	if (argc != 2)
	{
		if (argc > 2)
			std::cerr << "Error: too many arguments" << std::endl;
		else
			std::cerr << "Error: missing data. Usage: ./scalarConverter [data]" << std::endl;
		return 1;
	}
	
	int result = parse(argv[1]);

	switch (result)
	{
        case UNKNOWN :
		  	std::cout << "unknown";
			break;
		case CHAR :
			std::cout << "char";
			break;
		case INT :
			std::cout << "int";
			break;
		case FLOAT :
			std::cout << "float";
			break;
		case DOUBLE :
			std::cout << "double";
    }
	std::cout << std::endl;

	ScalarConverter a;

	a.convert("*");
}



