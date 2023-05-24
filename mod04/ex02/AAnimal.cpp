#include "AAnimal.hpp"

Animal::Animal(void)
{
	type = "Animalia";
	name = "Animalia";
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHGREEN << "[Animal]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
}

Animal&Animal::operator=(const Animal &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		name = copy.name;
	}
	return *this;
}

Animal::~Animal(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHGREEN << "[Animal]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

std::string Animal::getType(void) const
{
	return type;
}

std::string Animal::getName(void) const
{
	return name;
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

void Animal::setName(const std::string &name)
{
	this->name = name;
}

std::ostream &operator<<(std::ostream &os, const Animal &animal)
{
	os << animal.getType();
	return os;
}
