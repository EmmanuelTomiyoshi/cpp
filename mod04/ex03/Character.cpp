#include "Character.hpp"

Character::Character(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Character]" << " default constructor called" << std::endl;
	}
	// _slots[0] = new Ice();
}

Character::Character(const Character &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Character]" << " copy constructor called" << std::endl;
	}
	*this = copy;
}

Character&Character::operator=(const Character &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Character]" << " copy assignment operator called" << std::endl;
	}
	if (this != &copy)
	{
		//
	}
	return *this;
}

Character::~Character(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Character]" << " default destructor called" << std::endl;
	}
}

std::string const &Character::getName(void) const
{
	return _name;
}

void Character::equip(AMateria *m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter &target)
{

}
