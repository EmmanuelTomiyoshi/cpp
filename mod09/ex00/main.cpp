#include "BitcoinExchange.hpp"
#include <iostream>

//associar um valor a uma data "date / value"
//map

//2) stack


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error. Usage: ./btc <input_file>" << std::endl;
		return 1;
	}


	parse(std::string(argv[1]));


	// std::map<std::string, double> dateValue;

	// dateValue["A"] = 2;
	// dateValue["B"] = 3;
	// dateValue["C"] = 4;

	// std::cout << dateValue["Z"] << std::endl;
	// std::cout << dateValue["A"] << std::endl;
	// std::cout << dateValue["B"] << std::endl;



	// try
	// {
	// 	BitcoinExchange btc;
	// 	btc.readDatabase("data.csv");
	// 	btc.readInputFile(std::string(argv[1]));
	// }
	// catch (std::exception &e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// 	return 1;
	// }


}