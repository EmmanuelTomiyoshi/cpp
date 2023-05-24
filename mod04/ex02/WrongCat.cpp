#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "WrongCat";
	name = "wrongCat";
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHRED << "[WrongCat]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
	*this = copy;
}

WrongCat&WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		name = copy.name;
	}
	return *this;
}

WrongCat::~WrongCat(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHRED << "[WrongCat]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal()
{
	this->type = "WrongCat";
	this->name = name;
	this->name.at(0) = std::toupper(this->name.at(0));
	std::cout << COLOR_BHRED << "[WrongCat] " << COLOR_RESET
	<< name << " has entered the house" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "\"woem\"";
}