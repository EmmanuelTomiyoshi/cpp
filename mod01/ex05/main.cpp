#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	Harl obj;

	if (argc == 1)
	{
		obj.complain("DEBUG");
		obj.complain("INFO");
		obj.complain("WARNING");
		obj.complain("ERROR");
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				argv[i][j] = toupper(argv[i][j]);
			obj.complain(argv[i]);
		}
	}
}