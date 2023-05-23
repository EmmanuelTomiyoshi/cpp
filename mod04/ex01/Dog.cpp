#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE << "[Dog]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
	type = "Dog";
	name = "dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal()
{
	_brain = new Brain();
	*this = copy;
}

Dog&Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		name = copy.name;
		*_brain = *copy._brain;
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
	delete _brain;
}

Dog::Dog(const std::string &name) : Animal()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE "[Dog] " << COLOR_RESET << name
		<< " has entered the house" << std::endl;
	}
	this->type = "Dog";
	this->name = name;
	this->name.at(0) = std::toupper(this->name.at(0));
	_brain = new Brain();
}

void Dog::makeSound(void) const
{
	std::cout << "woof";
}