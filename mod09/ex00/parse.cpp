#include "BitcoinExchange.hpp"

bool isWhitespaceLine(const std::string &line)
{
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it)
	{
		if (!std::isspace(*it))
			return false;
	}
	return true;
}

bool isLeapYear(unsigned int year)
{
	//Leap years are divisible by 4
	//There is an exception: Years divisible by 100 are not leap years, unless they are divisible by 400
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidValue(const std::string value)
{
	char *endptr;
	double number = strtod(value.c_str(), &endptr);

	if (*endptr != '\0')
	{
		std::cout << "Error: " << ERR_VALUE_IS_NAN " " << std::endl;
		return false;
	}
	
	if (number < 0.0)
	{
		std::cout << "Error: " << ERR_VALUE_TOO_LOW " " << std::endl;
		return false;
	}
	else if (number > 1000.0)
	{
		std::cout << "Error: " << ERR_VALUE_TOO_HIGH " " << std::endl;
		return false;
	}

	return true;
}

void handleFileErrors(std::ifstream &inputFile)
{
	if (!inputFile.is_open())
		throw std::invalid_argument("Failed to open the file. It either doesn\'t exist or has wrong permissions");

	if (inputFile.peek() == std::ifstream::traits_type::eof())
		throw std::length_error("File is empty");
}
