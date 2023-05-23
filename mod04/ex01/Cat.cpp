#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cat]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
	type = "Cat";
	name = "cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cat]" << COLOR_RESET
		<< " copy constructor called" << std::endl;
	}
	_brain = new Brain();
	*this = copy;
}

Cat&Cat::operator=(const Cat &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cat]" << COLOR_RESET
		<< " copy assignment operator called" << std::endl;
	}
	if (this != &copy)
	{
		type = copy.type;
		name = copy.name;
		*_brain = *copy._brain;
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
	delete _brain;
}

Cat::Cat(const std::string &name) : Animal()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cat] " << COLOR_RESET << name
		<< " has entered the house" << std::endl;
	}
	this->type = "Cat";
	this->name = name;
	this->name.at(0) = std::toupper(this->name.at(0));
	_brain = new Brain();
}

void Cat::makeSound(void) const
{
	std::cout << "meow";
}