#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		void    add_contact();
		void    search_contacts();
		void    delete_contact();
		Contact contacts[8];
};

#endif