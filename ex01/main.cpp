
#include <iostream>
#include <string>
#include <vector>


inline std::string NewPrompt()
{
	return "\e[2J\e[1;1H";
}

class Contact{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook
{
	public:
		void add_contact();
		void search_contacts();
		void delete_contact();
	private:
		std::vector<Contact> contacts;
};


void PhoneBook::add_contact()
{
	Contact new_contact;
	std::cout << "Enter first name:";
	getline(std::cin, new_contact.first_name);
	std::cout << "Enter last name:";
	getline(std::cin, new_contact.last_name);
	std::cout << "Enter nickname:";
	getline(std::cin, new_contact.nickname);
	std::cout << "Enter phone number:";
	getline(std::cin, new_contact.phone_number);
	std::cout << "Enter darkest secret:";
	getline(std::cin, new_contact.darkest_secret);
	std::cout << NewPrompt();
}

void PhoneBook::search_contacts()
{

}

void PhoneBook::delete_contact()
{

}

int main()
{
	PhoneBook	pb;
	std::string		cmd;

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
			break;
		else
		{
			std::cout << NewPrompt();
			std::cout << "Invalid command, try again one of the following: ADD, SEARCH, DELETE, EXIT" << std::endl;
		}
	}
}
