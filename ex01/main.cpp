
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "String.hpp"
#include <cstdlib>
#include <string>
#include <iomanip>

int main()
{
	PhoneBook		pb;
	std::string		cmd;

	while (true)
	{
		display_menu();
		getline(std::cin, cmd);
		if (check_eof() == true || cmd == "EXIT")
			break ;
		else if (cmd.empty())
			continue ;
		else if (cmd == "clear")
			std::cout << NewPrompt();
		else if (cmd == "ADD")
		{
			if (!pb.add_contact())
				break ;
		}
		else if (cmd == "SEARCH")
		{
			if (!pb.search_contacts())
				break ;
		}
		else
			msg_invalid_cmd();
	}
	msg_exiting_program();
}
