#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

		int	add_contact();
		int	search_contacts();
		void save_contacts();
	
	private:

		static int	_index;
		static int	_size;
		static int	_qttcontacts;	
		Contact _contacts[8];
};

#endif