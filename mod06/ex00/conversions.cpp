#include "ScalarConverter.hpp"

void toChar(const std::string type, t_convert &convert)
{
	convert._typeChar = type[0];
	convert._typeInt = static_cast<int>(convert._typeChar);
	convert._typeFloat = static_cast<float>(convert._typeChar);
	convert._typeDouble = static_cast<double>(convert._typeChar);

	displayTypes(convert);
}

void toInt(const std::string type, t_convert &convert)
{
	convert._typeInt = std::atof(type.c_str());
	convert._typeChar = static_cast<char>(convert._typeInt);
	convert._typeFloat = static_cast<float>(convert._typeInt);
	convert._typeDouble = static_cast<double>(convert._typeInt);

	displayTypes(convert);
}

void toFloat(const std::string type, t_convert &convert)
{
	convert._typeFloat = std::atof(type.c_str());
	convert._typeChar = static_cast<char>(convert._typeFloat);
	convert._typeInt = static_cast<int>(convert._typeFloat);
	convert._typeDouble = static_cast<double>(convert._typeFloat);

	displayTypes(convert);
}

void toDouble(const std::string type, t_convert &convert)
{
	long double _value = std::strtold(type.c_str(), NULL);
	if (_value > DBL_MAX || _value < -DBL_MAX)
	{
		displayAllImpossible();
		return ;
	}
	convert._typeDouble = static_cast<double>(_value);
	convert._typeChar = static_cast<char>(convert._typeDouble);
	convert._typeInt = static_cast<int>(convert._typeDouble);
	convert._typeFloat = static_cast<float>(convert._typeDouble);

	displayTypes(convert);
}

void toPseudoFloat(const std::string type, t_convert &convert)
{
	convert._typeDouble = std::atof(type.c_str());
	convert._typeChar = static_cast<char>(convert._typeDouble);
	convert._typeInt = static_cast<int>(convert._typeDouble);
	convert._typeFloat = static_cast<float>(convert._typeDouble);

	displayTypes(convert);
}

void toPseudoDouble(const std::string type, t_convert &convert)
{
	convert._typeDouble = std::atof(type.c_str());
	convert._typeChar = static_cast<char>(convert._typeDouble);
	convert._typeInt = static_cast<int>(convert._typeDouble);
	convert._typeFloat = static_cast<float>(convert._typeDouble);

	displayTypes(convert);
}
