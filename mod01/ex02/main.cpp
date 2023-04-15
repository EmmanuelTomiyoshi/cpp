#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string *stringREF = stringPTR;

	std::cout << "Memory address from str: " << &str << std::endl;
	std::cout << "Memory address from stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address from stringREF: " << stringREF << std::endl;

	if (&str != stringPTR && stringREF != stringPTR)
		return (std::cout << "Memory adresses doesn\'t match" << std::endl, 1);
	std::cout << "It\'s a match!" << std::endl;
}