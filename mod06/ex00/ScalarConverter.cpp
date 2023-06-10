#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _typeChar(0), _typeInt(0), _typeFloat(0), _typeDouble(0)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ScalarConverter] default constructor called" << std::endl;
	}
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) : _typeChar(0), _typeInt(0), _typeFloat(0), _typeDouble(0)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ScalarConverter] copy constructor called" << std::endl;
	}
	*this = copy;
}

ScalarConverter&ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ScalarConverter] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		_typeChar = copy._typeChar;
		_typeInt = copy._typeInt;
		_typeFloat = copy._typeFloat;
		_typeDouble = copy._typeDouble;
	}
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ScalarConverter] destructor called" << std::endl;
	}
}

static size_t countCharacters(const std::string &str, char c)
{
	size_t count = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c)
			count++;
	}
	return count;
}

static bool isChar(const std::string &str)
{
	return (str.length() == 1 && !std::isdigit(str.at(0)));
}

static bool isInt(const std::string &str)
{
	if (std::atoi(str.c_str()) != 0 || countCharacters(str, '0') == str.length())
	{
		return true;
	}
	return false;
}

static bool isFloat(const std::string &str)
{
	if (countCharacters(str, 'f') == 1 || countCharacters(str, 'F') == 1)
	{
		if (std::tolower(str.at(str.length() - 1)) == 'f')
		{
			if (std::atof(str.c_str()) || countCharacters(str, '0' != str.length()))
			{
				return true;
			}
		}
	}
	return false;
}

static bool isDouble(const std::string &str)
{
	size_t pos = str.find('.');
	std::string sub1 = str.substr(0, pos);
	std::string sub2 = str.substr(pos + 1, str.length());

	if ((std::atol(sub1.c_str()) || countCharacters(sub1, '0') == sub1.length() || sub1.length() == 0)
		&& (std::atol(sub2.c_str()) || countCharacters(sub2, '0') == sub2.length() || sub2.length() == 0))
	{
		return true;
	}
	return false;
}

static bool isValidNumber(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str.at(0) == '+' || str.at(0) == '-')
			continue ;
		else if (i == str.length() - 1)
		{
			if (!std::isdigit(str.at(i)) && str.at(i) != 'f' && str.at(i) != 'F' && str.at(i) != '.')
			{
				return false;
			}
		}
		else if (!std::isdigit(str.at(i)) && str.at(i) != '.')
			return false;
	}
	return true;
}

t_scalarTypes parse(const std::string &type)
{
	if (!type.length())
		return UNKNOWN;

	if (isChar(type))
		return CHAR;
	
	if (!isValidNumber(type))
		return UNKNOWN;

	if (countCharacters(type, '.') == 0)
	{
		if (isInt(type))
			return INT;
	}
	else if (countCharacters(type, '.') == 1)
	{
		if (isFloat(type))
			return FLOAT;
		else if (isDouble(type))
			return DOUBLE;
	}

	return UNKNOWN;
}

void ScalarConverter::toChar(const std::string &type)
{
	_typeChar = type.at(0);
	_typeInt = static_cast<int>(_typeChar);
	_typeFloat = static_cast<float>(_typeChar);
	_typeDouble = static_cast<double>(_typeChar);
}

void ScalarConverter::toInt(const std::string &type)
{
	_typeInt = std::atoi(type.c_str());
	_typeChar = static_cast<char>(_typeInt);
	_typeFloat = static_cast<float>(_typeInt);
	_typeDouble = static_cast<double>(_typeInt);
}

void ScalarConverter::toFloat(const std::string &type)
{
	_typeFloat = std::atof(type.c_str());
	_typeChar = static_cast<char>(_typeFloat);
	_typeInt = static_cast<int>(_typeFloat);
	_typeDouble = static_cast<double>(_typeFloat);
}

void ScalarConverter::toDouble(const std::string &type)
{
	_typeDouble = std::atol(type.c_str());
	_typeChar = static_cast<char>(_typeDouble);
	_typeInt = static_cast<int>(_typeDouble);
	_typeFloat = static_cast<float>(_typeDouble);
}

// void ScalarConverter::displayChar(void) const
// {
// 	if (!std::isprint(_typeChar))
// 	{
// 		std::cout << "Non displayable";
// 	}
// 	else if (_typeChar < 0 || _typeChar > 127)
// 	{
// 		std::cout << "impossible";
// 	}
// }

void ScalarConverter::convert(const std::string &type)
{
	// t_scalarTypes result = parse(type);

	// std::cout << "char: " << c
	// << " | int: " << i
	// << " | float: " << f
	// << " | double: " << d << std::endl;
}
