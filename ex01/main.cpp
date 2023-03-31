
#include "Commons.hpp"
#include "Format.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook		pb;
	Format			f;
	std::string		cmd;

	while (true)
	{
		f.display_menu();
		getline(std::cin, cmd);
		if (f.check_eof() == true || cmd == "EXIT")
			break ;
		else if (cmd.empty() || f.whitespaces(cmd))
			continue ;
		else if (cmd == "clear")
			std::cout << f.NewPrompt();
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
			f.msg_invalid_cmd();
	}
	f.msg_exiting_program();
}
