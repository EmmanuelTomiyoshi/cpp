#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <iterator>

int	PhoneBook::_index = 0;
int	PhoneBook::_qttcontacts = 0;

void PhoneBook::add_contact()
{
	std::string	labels[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	std::string input;
	for (int i = 0; i < 5; i++)
	{
		bool is_input_valid = false;
		if (PhoneBook::_index == 8)
			PhoneBook::_index = 0;
		while (!is_input_valid)
		{
			std::cout << labels[i];
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::cout << '\n';
				return ;
			}
			if (!input.empty())
				is_input_valid = true;	
			switch (i)
			{
				case 0:
					_contacts[PhoneBook::_index].setFirstName(input);
					break;
				case 1:
					_contacts[PhoneBook::_index].setLastName(input);
					break;
				case 2:
					_contacts[PhoneBook::_index].setNickname(input);
					break;
				case 3:
					_contacts[PhoneBook::_index].setPhoneNumber(input);
					break;
				case 4:
					_contacts[PhoneBook::_index].setDarkestSecret(input);
					break;
			}
		}
	}
	if (_qttcontacts != 8)
		_qttcontacts++;
	PhoneBook::_index += 1;
}

std::string format_column(std::string text)
{
	if (text.length() > 10)
	{
		text.resize(9);
		text.append(".");
	}
	return (text);
}

void display_header(std::string header)
{
    int width = 43;

    int padding = width - header.length();
    int left_padding = padding/2;
    int right_padding = padding - left_padding;

    std::cout << std::setfill('=') << std::setw(left_padding) << "" << header << std::setw(right_padding) << "" << std::endl;
	std::cout << std::setfill(' '); //reseting setfill
}

void PhoneBook::search_contacts()
{
	if (_qttcontacts == 0)
	{
		std::cout << "PhoneBook is Empty. Please add at least 1 contact." << std::endl;
		return ;
	}
	display_header(" CONTACTS ");

	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	for (int i = 0; i < PhoneBook::_index; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << format_column(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << format_column(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << format_column(_contacts[i].getNickname()) << std::endl;
	}
	std::cout << "===========================================" << std::endl;
}
