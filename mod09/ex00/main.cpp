#include "BitcoinExchange.hpp"
#include <iostream>

//2) stack

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error. Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	try
	{
		btc.readDatabase("data.csv");
		btc.readInputFile(std::string(argv[1]));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
