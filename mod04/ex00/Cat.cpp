#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
	name = "cat";
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cat]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
}

Cat::Cat(const Cat &copy) : Animal()
{
	*this = copy;
}

Cat&Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		name = copy.name;
	}
	return *this;
}

Cat::~Cat(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cat]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

Cat::Cat(const std::string &name) : Animal()
{
	this->type = "Cat";
	this->name = name;
	this->name.at(0) = std::toupper(this->name.at(0));
	std::cout << COLOR_BHYELLOW << "[Cat] " << COLOR_RESET << name
	<< " has entered the house" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "meow";
}