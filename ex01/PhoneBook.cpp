#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>

#include <stdlib.h> //remove later

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


int getIntegerInRange(int min, int max) {
    int value;
    while (true) {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        std::string input;
        std::getline(std::cin, input);
        std::istringstream stream(input);
		if (input.empty())
			continue ;
        if (!(stream >> value) || (value < min || value > max)) {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
        }
        else {
            return value;
        }
    }
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



    int userInput = getIntegerInRange(0, PhoneBook::_index - 1); //minus one because index starts at 0, as always
	display_header(" CONTACTS ");
    std::cout << "First name: " << _contacts[userInput].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[userInput].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[userInput].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[userInput].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[userInput].getDarkestSecret() << std::endl;
	std::cout << "===========================================" << std::endl;

}


		// if (std::cin.eof())
		// {
		// 	std::cout << '\n';
		// 	std::cout << "There\'s no backup. Contacts are lost forever! =)" << std::endl << "Exiting the program..." << std::endl;
		// 	exit(0);
		// }