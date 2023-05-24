#ifndef EX02_CAT_HPP
#define EX02_CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat&operator=(const Cat &copy);
		~Cat(void);

		Cat(const std::string &name);

		Brain *getBrain(void) const;

		virtual void makeSound(void) const;

	private:
		Brain *_brain;

};

#endif // EX02_CAT_HPP