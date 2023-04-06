#include "Commons.hpp"
#include "Contact.hpp"

//getters
//return type, class name, function name <- in this order
const std::string Contact::getFirstName() const {
	return _first_name;
}

const std::string Contact::getLastName() const {
	return _last_name;
}

const std::string Contact::getNickname() const {
	return _nickname;
}

const std::string Contact::getPhoneNumber() const {
	return _phone_number;
}

const std::string Contact::getDarkestSecret() const {
	return _darkest_secret;
}

//setters
void Contact::setFirstName(const std::string fname) {
	_first_name = fname;
}
void Contact::setLastName(const std::string lname) {
	_last_name = lname;
}
void Contact::setNickname(const std::string nick) {
	_nickname = nick;
}
void Contact::setPhoneNumber(const std::string pnumber) {
	_phone_number = pnumber;
}
void Contact::setDarkestSecret(const std::string dsecret) {
	_darkest_secret = dsecret;
}