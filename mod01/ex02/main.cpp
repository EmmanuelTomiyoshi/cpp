#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address from str:\t" << &str << std::endl;
	std::cout << "Memory address from stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address from stringREF:\t" << &stringREF << std::endl;
}