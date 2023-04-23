#include "Harl.hpp"

void Harl::complain (std::string level) {
	options_t opt[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	int i = 0;
	for (; i < 4; i++)
	{
		if (opt[i].name == level)
			break ;
	}
	switch (i)
	{
		default:
			std::cout << "Probably working at the NetPractice bonus" << std::endl;
			break ;
		case 0:
			(this->*opt[0].f)();
			// fallthrough
		case 1:
			(this->*opt[1].f)();
			// fallthrough
		case 2:
			(this->*opt[2].f)();
			// fallthrough
		case 3:
			(this->*opt[3].f)();
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
