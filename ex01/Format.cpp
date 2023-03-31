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
	std::cout << std::endl;
	std::cout << "    ________________________   ________________________" << std::endl;
	std::cout << ".-/|                        \\ /                        |\\-." << std::endl;
	std::cout << "||||                         |                         ||||" << std::endl;
	std::cout << "||||    Welcome to           |   \001\033[0;94m\002MENU:\001\033[0m\002                 ||||" << std::endl;
	std::cout << "||||    my awesome           |                         ||||" << std::endl;
	std::cout << "||||    PhoneBook!           |   \001\033[0;94m\002(1)\001\033[0m\002 ADD CONTACT       ||||" << std::endl;
	std::cout << "||||                         |   \001\033[0;94m\002(2)\001\033[0m\002 SEARCH CONTACTS   ||||" << std::endl;
	std::cout << "||||    --==*==--            |   \001\033[0;94m\002(3)\001\033[0m\002 CLEAR SCREEN      ||||" << std::endl;
	std::cout << "||||                         |   \001\033[0;94m\002(4)\001\033[0m\002 EXIT              ||||" << std::endl;
	std::cout << "||||    Project made         |                         ||||" << std::endl;
	std::cout << "||||    by: etomiyos         |                         ||||" << std::endl;
	std::cout << "||||                         |                         ||||" << std::endl;
	std::cout << "||||________________________ | ________________________||||" << std::endl;
	std::cout << "||/=========================\\|/=========================\\||" << std::endl;
	std::cout << "`--------------------------~___~-------------------------''" << std::endl;
	std::cout << std::endl;

}

void Format::display_prompt()
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

void Format::msg_invalid_input(void)
{
	std::cout << "Invalid input, try again one of the following:" << std:: endl << "(1) ADD | (2) SEARCH | (3) CLEAR | (4) EXIT" << std::endl;
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
