#include "AMateria.hpp"

AMateria::AMateria(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AMateria]" << " default constructor called" << std::endl;
	}
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria&AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

AMateria::~AMateria(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AMateria]" << " default destructor called" << std::endl;
	}
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AMateria]" << " custom constructor called" << std::endl;
	}
}

std::string const &AMateria::getType(void) const
{
	return _type;
}

void AMateria::setType(const std::string &type)
{
	_type = type;
}

std::ostream &operator<<(std::ostream &os, const AMateria &animal)
{
	os << animal.getType();
	return os;
}
