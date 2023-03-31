
#include "Commons.hpp"
#include "Format.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook		pb;
	Format			format;
	std::string		cmd;

	while (true)
	{
		format.display_menu();
		getline(std::cin, cmd);
		if (format.check_eof() == true || cmd == "EXIT")
			break ;
		else if (cmd.empty() || format.whitespaces(cmd))
			continue ;
		else if (cmd == "clear")
			std::cout << format.NewPrompt();
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
			format.msg_invalid_input();
	}
	format.msg_exiting_program();
}
