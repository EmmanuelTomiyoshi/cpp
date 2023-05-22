#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	type = "Animalia";
	name = "Animalia";
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHRED << "[WrongAnimal]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
}

WrongAnimal&WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		name = copy.name;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHRED << "[WrongAnimal]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "---";
}

std::string WrongAnimal::getType(void) const
{
	return type;
}

std::string WrongAnimal::getName(void) const
{
	return name;
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}

void WrongAnimal::setName(const std::string &name)
{
	this->name = name;
}

std::ostream &operator<<(std::ostream &os, const WrongAnimal &WrongAnimal)
{
	os << WrongAnimal.getType();
	return os;
}
