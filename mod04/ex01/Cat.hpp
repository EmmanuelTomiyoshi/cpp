#ifndef EX01_CAT_HPP
#define EX01_CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat&operator=(const Cat &copy);
		~Cat(void);

		Cat(const std::string &name);

		virtual void makeSound(void) const;

	private:
		Brain *_brain;

};

#endif // EX01_CAT_HPP