#ifndef EX00_CAT_HPP
#define EX00_CAT_HPP

#include <iostream>
#include "Animal.hpp"

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

};

#endif // EX00_CAT_HPP