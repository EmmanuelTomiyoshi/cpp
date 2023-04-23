#include "Harl.hpp"

void Harl::complain (std::string level) {
	options_t opt[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (opt[i].name == level)
		{
			return (this->*opt[i].f)();
		}
	}
}

void Harl::debug (void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I\'ve been 40 hours trying to debug this code and I still don\'t know how to solve it" << std::endl;
}

void Harl::info (void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Download the Doctest first in order to test your program!" << std::endl;
}

void Harl::warning (void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Make tests...always" << std::endl;
}

void Harl::error (void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "See? If you were to use tests, you would not be crying right now" << std::endl;
}
