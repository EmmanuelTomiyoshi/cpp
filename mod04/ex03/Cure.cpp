#include "Cure.hpp"

Cure::Cure(void) : AMateria()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cure]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
	_type = "cure";
}

Cure::Cure(const Cure &copy) : AMateria()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cure]" << COLOR_RESET
		<< " copy constructor called" << std::endl;
	}
	*this = copy;
}

Cure&Cure::operator=(const Cure &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cure]" << COLOR_RESET
		<< " copy assignment operator called" << std::endl;
	}
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

Cure::~Cure(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHYELLOW << "[Cure]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

AMateria *Cure::clone(void) const  
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *";
}