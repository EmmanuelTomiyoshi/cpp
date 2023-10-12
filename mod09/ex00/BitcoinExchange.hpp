#ifndef EX01_BITCOINEXCHANGE_HPP
#define EX01_BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <map>

#define DATE_LENGTH				10
#define YEAR_CHAR_LENGTH		4
#define MONTH_CHAR_LENGTH		2
#define DAY_CHAR_LENGTH			2

#define SHOW_DEFAULT_MESSAGES	0

#define ERR_BAD_INPUT				"Bad input"
#define ERR_DATE_WRONG_FORMAT		"Date has wrong format."
#define ERR_DATE_WRONG_BOUND		"Date has an impossible day or month."
#define ERR_DATE_WRONG_RANGE		"Date must be between 2009-01-03 and the current date."
#define ERR_VALUE_IS_NAN			"The value is not a number."
#define ERR_VALUE_TOO_LOW			"The number is not positive."
#define ERR_VALUE_TOO_HIGH			"The number is too large."

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange&operator=(const BitcoinExchange &copy);

		void readDatabase(std::string database);
		void readInputFile(std::string filename);

		void isValidEntry(const std::string line);

		class HeadlineIsInvalid: public std::invalid_argument
		{
			public:
				HeadlineIsInvalid() :
				std::invalid_argument("The first line of the file is incorrect. Usage: \"date | value\""){};
		};

	private:

		std::map<std::string, double>	_database;
		static const std::string		_headline[];

		void	checkHeadline(std::string line);
		bool	checkDate(const std::string date);

};

bool	isWhitespaceLine(const std::string &line);
bool	isLeapYear(unsigned int year);
bool 	isValidValue(const std::string value);
void	handleFileErrors(std::ifstream &inputFile);

#endif // EX01_BITCOINEXCHANGE_HPP