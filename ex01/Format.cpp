#include "Commons.hpp"
#include "Format.hpp"

std::string Format::color_yellow(void)
{
	return "\001\033[0;33m\002";
}

std::string Format::NewPrompt()
{
	return "\033[2J\033[1;1H";
}

std::string Format::color_reset()
{
	return "\001\033[0m\002";
}

void Format::display_menu()
{
	std::cout << color_yellow() << "[PhoneBook] " << color_reset() << "Enter command: ";
}

bool Format::check_eof()
{
	if (std::cin.eof())
	{
		std::cout << '\n';
		return (true);
	}
	return (false);
}

void Format::msg_exiting_program(void)
{
	std::cout << "There\'s no backup. Contacts are lost forever! =)" << std::endl << "Exiting the program..." << std::endl;
}

void Format::msg_invalid_cmd(void)
{
	std::cout << "Invalid command, try again one of the following: ADD, SEARCH, EXIT" << std::endl;
}

std::string Format::column(std::string text)
{
	if (text.length() > 10)
	{
		text.resize(9);
		text.append(".");
	}
	return (text);
}

void Format::display_header(std::string header)
{
    int width = 43;

    int padding = width - header.length();
    int left_padding = padding/2;
    int right_padding = padding - left_padding;

    std::cout << std::setfill('=') << std::setw(left_padding) << "" << header << std::setw(right_padding) << "" << std::endl;
	std::cout << std::setfill(' '); //reseting setfill
}

bool Format::whitespaces(std::string input)
{
	for (std::size_t i = 0; i < input.length(); i++)
	{
		if (!isspace(input[i]))
			return false;
	}
	return true;
}
