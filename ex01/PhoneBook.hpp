#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	public:
		void    add_contact();
		void    search_contacts();
	
	private:
		static int	_index;
		static int	_qttcontacts;	
		Contact _contacts[8];
};

#endif