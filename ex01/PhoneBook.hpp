#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		void    add_contact();
		void    search_contacts();
		void    delete_contact();
	
	private:
		static int	_j;
		static int	_qttcontacts;	
		Contact _contacts[8];
};

#endif