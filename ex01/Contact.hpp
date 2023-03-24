#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

# define MSG_ERR_INVALID_ARGC "Invalid number of arguments, please only use ./contact"

class Contact{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif