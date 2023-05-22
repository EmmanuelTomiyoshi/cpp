#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	name = "dog";
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE << "[Dog]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
}

Dog::Dog(const Dog &copy) : Animal()
{
	*this = copy;
}

Dog&Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		name = copy.name;
	}
	return *this;
}

Dog::~Dog(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE << "[Dog]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

Dog::Dog(const std::string &name) : Animal()
{
	this->type = "Dog";
	this->name = name;
	this->name.at(0) = std::toupper(this->name.at(0));
	std::cout << COLOR_BHBLUE "[Dog] " << COLOR_RESET << name
	<< " has entered the house" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "woof";
}
