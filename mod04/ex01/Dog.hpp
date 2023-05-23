#ifndef EX01_DOG_HPP
#define EX01_DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

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
		Brain *_brain;

};

#endif // EX01_DOG_HPP