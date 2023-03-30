#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <istream>
#include <string>

class String{

};

inline std::string color_yellow(void)
{
	return "\001\033[0;33m\002";
}

inline std::string NewPrompt()
{
	return "\033[2J\033[1;1H";
}

inline std::string color_reset(void)
{
	return "\001\033[0m\002";
}

inline void display_menu(void)
{
	std::cout << color_yellow() << "[PhoneBook] " << color_reset() << "Enter command: ";
}

inline bool check_eof()
{
	if (std::cin.eof())
	{
		std::cout << '\n';
		return (true);
	}
	return (false);
}

inline void msg_exiting_program(void)
{
	std::cout << "There\'s no backup. Contacts are lost forever! =)" << std::endl << "Exiting the program..." << std::endl;
}

inline void msg_invalid_cmd(void)
{
	std::cout << "Invalid command, try again one of the following: ADD, SEARCH, EXIT" << std::endl;
}

#endif