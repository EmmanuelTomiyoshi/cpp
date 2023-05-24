#ifndef EX02_DOG_HPP
#define EX02_DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	
	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog&operator=(const Dog &copy);
		~Dog(void);

		Dog(const std::string &name);

		Brain *getBrain(void) const;

		virtual void makeSound(void) const;

	private:
		Brain *_brain;

};

#endif // EX02_DOG_HPP