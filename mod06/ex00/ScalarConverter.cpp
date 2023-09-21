#include "ScalarConverter.hpp"

void displayAllImpossible(void)
{
	std::cout << "char: impossible \n int: impossible \n \
	float: impossible \n double: impossible" << std::endl;
}

void displayTypes(t_convert &convert)
{
	//check for CHAR
	if (!isascii(convert._typeInt))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(convert._typeChar))
		std::cout << "char: " << convert._typeChar << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;

	//check for INT
	if (convert._tempNum >= INT_MIN && convert._tempNum <= INT_MAX && !(std::isnan(convert._typeFloat) || std::isnan(convert._typeDouble) || std::isinf(convert._typeFloat) || std::isinf(convert._typeDouble)))
        std::cout << "int: " << convert._typeInt << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	std::cout << "float: " << convert._typeFloat << "f" << std::endl;
	std::cout << "double: " << convert._typeDouble << std::endl;
}

void ScalarConverter::convert(std::string type)
{
	t_convert	convert;

	t_scalarTypes output = parse(type);
	convert._tempNum = atoll(type.c_str()); //stores in order to check for min and max values

	switch (output)
	{
        case UNKNOWN :
			break;
		case CHAR :
			toChar(type, convert);
			break;
		case INT :
			toInt(type, convert);
			break;
		case FLOAT :
			toFloat(type, convert);
			break;
		case DOUBLE :
			toDouble(type, convert);
			break;
		case PSEUDO_FLOAT :
			toPseudoFloat(type, convert);
			break;
		case PSEUDO_DOUBLE :
			toPseudoDouble(type, convert);
			break;
    }
}
