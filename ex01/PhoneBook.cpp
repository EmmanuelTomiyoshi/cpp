#include "PhoneBook.hpp"

int	PhoneBook::_j = 0;
int	PhoneBook::_qttcontacts = 0;

void PhoneBook::add_contact()
{
	std::string	labels[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	std::string input;

	for (int i = 0; i < 5; i++)
	{
		bool is_input_valid = false;
		if (PhoneBook::_j == 8)
			PhoneBook::_j = 0;
		while (!is_input_valid)
		{
			std::cout << labels[i];
			std::getline(std::cin, input);
			if (!input.empty())
				is_input_valid = true;	
			switch (i)
			{
				case 0:
					_contacts[PhoneBook::_j].setFirstName(input);
					break;
				case 1:
					_contacts[PhoneBook::_j].setLastName(input);
					break;
				case 2:
					_contacts[PhoneBook::_j].setNickname(input);
					break;
				case 3:
					_contacts[PhoneBook::_j].setPhoneNumber(input);
					break;
				case 4:
					_contacts[PhoneBook::_j].setDarkestSecret(input);
					break;
			}
		}
	}
	// std::cout << "(" << _contacts[_j].getFirstName() << ")";
	// std::cout << "(" << _contacts[_j].getLastName() << ")";
	// std::cout << "(" << _contacts[_j].getNickname() << ")";
	// std::cout << "(" << _contacts[_j].getPhoneNumber() << ")";
	// std::cout << "(" << _contacts[_j].getDarkestSecret() << ")";
	if (_qttcontacts != 8)
		_qttcontacts++;
	PhoneBook::_j += 1;
}
