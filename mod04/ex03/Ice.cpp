#include "Ice.hpp"

Ice::Ice(void) : AMateria()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE << "[Ice]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
	_type = "ice";
}

Ice::Ice(const Ice &copy) : AMateria()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE << "[Ice]" << COLOR_RESET
		<< " copy constructor called" << std::endl;
		_type = "ice";
	}
	*this = copy;
}

Ice&Ice::operator=(const Ice &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE << "[Ice]" << COLOR_RESET
		<< " copy assignment operator called" << std::endl;
	}
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

Ice::~Ice(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHBLUE << "[Ice]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

AMateria *Ice::clone(void) const  
{
	return new Ice(*this); //will copy this Ice
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
	<< std::endl;
}