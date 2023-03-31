
#include "Commons.hpp"
#include "Format.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook		pb;
	Format			format;
	std::string		cmd;

	format.display_menu();
	while (true)
	{
		format.display_prompt();
		getline(std::cin, cmd);
		if (format.check_eof() == true || cmd == "4")
			break ;
		else if (cmd.empty() || format.whitespaces(cmd))
			continue ;
		else if (cmd == "3")
			std::cout << format.NewPrompt();
		else if (cmd == "1")
		{
			if (pb.add_contact() == false)
				break ;
		}
		else if (cmd == "2")
		{
			if (pb.search_contacts() == false)
				break ;
		}
		else
			format.msg_invalid_input();
	}
	format.msg_exiting_program();
}
