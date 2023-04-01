#include "Commons.hpp"
#include "PhoneBook.hpp"
#include "Format.hpp"

int	PhoneBook::_index = 0;
int PhoneBook::_size = 0;
int	PhoneBook::_qttcontacts = 0;

std::string hide_darkest_secret()
{
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    std::string secret;
    getline(std::cin, secret);
	std::cout << std::endl;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return (secret);
}

bool validateInput(std::string input, const std::string allowedChars, unsigned int minLenght) {

	if (input.length() < minLenght)
	{
		std::cout << "Input lenght must be at least: " << minLenght << std::endl;
		return false;
	}
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (allowedChars.find_first_of(input[i]) == std::string::npos)
		{
			std::cout << "Input invalid characters. Try again" << std::endl;
			return false;
		}
	}
	return true;
}

bool validate_field(std::string input, int index) {

	switch (index)
	{
		case 0:
			return validateInput(input, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.-\' ", 3);
		case 1:
			return validateInput(input, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.-\' ", 3);
		case 2:
			return validateInput(input, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 3);
		case 3:
			return validateInput(input, "0123456789", 3);
		case 4:
			return validateInput(input, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ", 1);
	}
	return (true);
}

int PhoneBook::add_contact()
{
	std::string	labels[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number (do not use \"()\" or \"+\" or \"-\"): ", "Darkest secret: "};
	std::string input;
	Format	f;
	for (int i = 0; i < 5; i++)
	{
		bool is_input_valid = false;
		if (PhoneBook::_index == 8)
			PhoneBook::_index = 0;
		while (!is_input_valid)
		{
			std::cout << labels[i];
			if (i == 4)
				input = hide_darkest_secret();
			else
				std::getline(std::cin, input);
			if (f.check_eof() == true)
				return (0);
			if (!input.empty())
				is_input_valid = true;
			if (validate_field(input, i) == false)
			{
				is_input_valid = false;
				continue ;
			}
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
	if (PhoneBook::_size == 8)
		;
	else
		PhoneBook::_size = PhoneBook::_index;
	return (1);
}

int getIntegerInRange(int min, int max) {
    int value;
	Format	f;
    while (true) {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        std::string input;
        std::getline(std::cin, input);
        std::istringstream stream(input);
		if (f.check_eof() == true)
			return (-1);
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

int PhoneBook::search_contacts()
{
	Format	f;
	if (_qttcontacts == 0)
	{
		std::cout << "PhoneBook is Empty. Please add at least 1 contact." << std::endl;
		return (1);
	}

	f.display_header(" CONTACTS ");
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	
	if (PhoneBook::_index == 8)
		PhoneBook::_size = 8;
	for (int i = 0; i < PhoneBook::_size; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << f.column(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << f.column(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << f.column(_contacts[i].getNickname()) << std::endl;
	}
	std::cout << "===========================================" << std::endl;

    int userInput = getIntegerInRange(0, PhoneBook::_size - 1); //minus one because index starts at 0, as always
	if (userInput == -1)
		return (0);
	f.display_header(" CONTACTS ");
    std::cout << "First name: " << _contacts[userInput].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[userInput].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[userInput].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[userInput].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[userInput].getDarkestSecret() << std::endl;
	std::cout << "===========================================" << std::endl;
	return (1);
}
