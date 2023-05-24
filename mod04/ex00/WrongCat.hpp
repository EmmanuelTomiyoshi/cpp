#ifndef EX00_WRONGCAT_HPP
#define EX00_WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	
	public:
		WrongCat(void);
		WrongCat(const WrongCat &copy);
		WrongCat&operator=(const WrongCat &copy);
		~WrongCat(void);

		WrongCat(const std::string &name);

		void makeSound(void) const;

	private:

};

#endif // EX00_WRONGCAT_HPP