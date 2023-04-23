#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	Harl obj;

	if (argc != 2)
		return (std::cout << "Usage:: ./harlFilter <level>" << std::endl, 1);
	obj.complain(argv[1]);
}