#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{

	public:
		const std::string getFirstName(void) const;
		const std::string getLastName(void) const;
		const std::string getNickname(void) const;
		const std::string getPhoneNumber(void) const;
		const std::string getDarkestSecret(void) const;

		void setFirstName(const std::string fname);
		void setLastName(const std::string lname);
		void setNickname(const std::string nick);
		void setPhoneNumber(const std::string pnumber);
		void setDarkestSecret(const std::string dsecret);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif