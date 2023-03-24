
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <string>

inline std::string NewPrompt()
{
	return "\033[2J\033[1;1H";
}

void PhoneBook::add_contact()
{
	Contact		new_contact;
	std::string	labels[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	std::string input;
	int			j = 0;

	for (int i = 0; i < 5; i++)
	{
		bool is_input_valid = false;

		while (!is_input_valid)
		{
			std::cout << labels[i];
			std::getline(std::cin, input);

			if (!input.empty())
				is_input_valid = true;
			switch (i)
			{
				case 0:
					contacts[j].first_name = input;
					break;
				case 1:
					contacts[j].last_name = input;
					break;
				case 2:
					contacts[j].nickname = input;
					break;
				case 3:
					contacts[j].phone_number = input;
					break;
				case 4:
					contacts[j].darkest_secret = input;
					break;
				j++;
			}
		}
	}

	
	// std::cout << "Enter first name:";
	// getline(std::cin, new_contact.first_name);
	// std::cout << "Enter last name:";
	// getline(std::cin, new_contact.last_name);
	// std::cout << "Enter nickname:";
	// getline(std::cin, new_contact.nickname);
	// std::cout << "Enter phone number:";
	// getline(std::cin, new_contact.phone_number);
	// std::cout << "Enter darkest secret:";
	// getline(std::cin, new_contact.darkest_secret);
	// std::cout << NewPrompt();

	// if (new_contact.first_name.empty())
	// 	;
}

void PhoneBook::search_contacts()
{

}

void PhoneBook::delete_contact()
{

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

int main(int argc, __attribute__((unused)) char **argv)
{
	//eof, CTRL+D

	PhoneBook		pb;
	std::string		cmd;

	if (check_invalid_args(&argc))
		return (EXIT_FAILURE);
	while (true)
	{
		std::cout << "Enter command: ";
		getline(std::cin, cmd);
		if (cmd == "ADD")
			pb.add_contact();
		else if (cmd == "SEARCH")
			pb.search_contacts();
		else if (cmd == "DELETE")
			pb.delete_contact();
		else if (cmd == "EXIT")
			break ;
		else
		{
			std::cout << NewPrompt();
			std::cout << "Invalid command, try again one of the following: ADD, SEARCH, DELETE, EXIT" << std::endl;
		}
	}
}
