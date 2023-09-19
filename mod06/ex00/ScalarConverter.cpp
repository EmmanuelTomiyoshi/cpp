#include "ScalarConverter.hpp"

void displayTypes(t_convert &convert)
{
	if (!isascii(convert._typeInt))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(convert._typeChar))
		std::cout << "char: " << convert._typeChar << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;

	if (convert._tempNum >= INT_MIN && convert._tempNum <= INT_MAX && !(std::isnan(convert._typeFloat) || std::isnan(convert._typeDouble) || std::isinf(convert._typeFloat) || std::isinf(convert._typeDouble)))
        std::cout << "int: " << convert._typeInt << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	std::cout << "float: " << convert._typeFloat << "f" << std::endl;
	std::cout << "double: " << convert._typeDouble << std::endl;
}

void ScalarConverter::convert(std::string type)
{
	t_convert convert;

	t_scalarTypes result = parse(type);
	convert._tempNum = atoll(type.c_str());

	switch (result)
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
			toPseudos(type, convert);
			break;
		case PSEUDO_DOUBLE :
			toPseudos(type, convert);
			break;
    }
}
