#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] constructor called" << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] copy constructor called" << std::endl;
	}
	*this = copy;
}

BitcoinExchange&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] destructor called" << std::endl;
	}
}

void BitcoinExchange::readDatabase(std::string database)
{
	std::ifstream file (database);

	if (!file.is_open())
	{
		throw "Error opening the file.";
	}

	int value;
	file >> value;
	
	if (file.eof())
		throw "The file is empty.";
	else if (file.fail())
		throw "Error reading from the file.";


	file.close();
}

void BitcoinExchange::readInputFile(std::string input_file)
{

}