#ifndef EX01_BITCOINEXCHANGE_HPP
#define EX01_BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <map>

#include "utils.cpp"

#define SHOW_DEFAULT_MESSAGES 0

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange&operator=(const BitcoinExchange &copy);

		void readDatabase(std::string database);
		void readInputFile(std::string input_file);

		// template <typename Iterator>
	private:
		std::map<std::string, float> dateValue;

};

bool parse(std::string filename);


#endif // EX01_BITCOINEXCHANGE_HPP