
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <string>
#include <iomanip>

inline std::string NewPrompt()
{
	return "\033[2J\033[1;1H";
}

bool	check_invalid_args(int *argc)
{
	if (*argc > 1)
	{
		std::cout << MSG_ERR_INVALID_ARGC << std::endl;
		return (true);
	}
	return (false);
}

inline std::string color_yellow(void)
{
	return "\001\033[0;33m\002";
}

inline std::string color_reset(void)
{
	return "\001\033[0m\002";
}

int main(int argc, __attribute__((unused)) char **argv)
{
	PhoneBook		pb;
	std::string		cmd;

	if (check_invalid_args(&argc))
		return (EXIT_FAILURE);
	while (true)
	{
		std::cout << color_yellow() << "[PhoneBook] " << color_reset() << "Enter command: ";
		getline(std::cin, cmd);
		if (std::cin.eof())
			std::cout << '\n';
		if (cmd == "ADD")
			pb.add_contact();
		if (cmd == "SEARCH")
			pb.search_contacts();
		else if (std::cin.eof() || cmd == "EXIT")
			break ;
		else if (cmd.empty())
			continue ;
		else if (cmd == "clear")
			std::cout << NewPrompt();
		else
			std::cout << "Invalid command, try again one of the following: ADD, SEARCH, DELETE, EXIT" << std::endl;
	}
	std::cout << "There\'s no backup. Contacts are lost forever! =)" << std::endl << "Exiting the program..." << std::endl;
}
