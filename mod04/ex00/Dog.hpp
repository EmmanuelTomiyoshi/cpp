#ifndef EX00_DOG_HPP
#define EX00_DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	
	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog&operator=(const Dog &copy);
		~Dog(void);

		Dog(const std::string &name);

		virtual void makeSound(void) const;

	private:

};

#endif // EX00_DOG_HPP