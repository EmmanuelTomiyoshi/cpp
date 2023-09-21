#include "ScalarConverter.hpp"

size_t countCharacters(std::string &str, char c)
{
	size_t count = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c)
			count++;
	}
	return count;
}

bool hasFCharacter(std::string &str)
{
	size_t found = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == 'F' || str[i] == 'f')
			found++;
	}
	if (found == 1)
		return true;
	else
		return false;
}

bool isChar(std::string str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

bool isValidNumber(std::string str)
{
	size_t length = str.length();

	if (str[length - 1] == 'f' || str[length - 1] == 'F')
		str.erase(length - 1, 1);

	size_t periodPosition = str.find('.');
	if (periodPosition != std::string::npos)
		str.erase(periodPosition, 1);

	length = str.length();

	for (size_t i = 0; i < length; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isInt(std::string str)
{
	size_t length = str.length();

	for (size_t i = 0; i < length; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isDouble(std::string str)
{
	size_t length = str.length();
	size_t countPeriod = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == '.')
			countPeriod++;
	}
	if (countPeriod == 1)
		return true;
	return false;
}

t_scalarTypes parse(std::string str)
{
	if (!str.length())
		return UNKNOWN;

	if (isChar(str))
		return CHAR;

	if ((str[0] == '+' || str[0] == '-'))
		str.erase(0, 1);

	//math stuff
	if (str == "inff" || str == "nanf")
	{
        return PSEUDO_FLOAT;
	}
    if (str == "inf" || str == "nan")
	{
        return PSEUDO_DOUBLE;
	}

	if (!isValidNumber(str))
		return UNKNOWN;

	int fPosition = str.find('f') || str.find('F');
	if (hasFCharacter(str) && str.find(fPosition))
		return FLOAT;
	
	if (isDouble(str))
		return DOUBLE;

	if (isInt(str))
		return INT;

	return UNKNOWN;
}