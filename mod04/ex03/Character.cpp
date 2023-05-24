#include "Ice.hpp"
#include "Character.hpp"

//inventory is initialized empty
Character::Character(void) : _inventory(), _deactivatedMateria()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Character]" << " default constructor called" << std::endl;
	}
}

Character::Character(const Character &copy) : _inventory(), _deactivatedMateria()
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
		for (int i = 0; i < SLOTS; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = 0;
			}

			if (copy._inventory[i])
				_inventory[i] = copy._inventory[i]->clone(); //deep copy with AMateria *clone()	
		}
		_name = copy._name;
	}
	return *this;
}

Character::~Character(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Character]" << " default destructor called" << std::endl;
	}

	if (_deactivatedMateria)
		delete _deactivatedMateria;
	
	for (int i = 0; i < SLOTS; i++)
		delete _inventory[i];
}

Character::Character(const std::string &name) : _inventory(), _deactivatedMateria()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Character]" << " custom constructor called" << std::endl;
	}
	_name = name;
}

std::string const &Character::getName(void) const
{
	return _name;
}

void Character::setName(const std::string &name)
{
	_name = name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < SLOTS; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "[Character]" << " succesfully added Materia at slot ["
			<< i << "]" << std::endl;
			return ;
		}
	}
	if (_deactivatedMateria)		//if inventory is full
		delete _deactivatedMateria;
	_deactivatedMateria = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > (SLOTS - 1))
		return ;

	if (_deactivatedMateria)
	{
		delete _deactivatedMateria;
		_deactivatedMateria = 0;
	}

	if (_inventory[idx])
	{
		_deactivatedMateria = _inventory[idx];
		std::cout << "[Character] Materia unequipped in slot " << idx << std::endl;
	}
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > (SLOTS - 1))
		return ;

	if (_inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}

const AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx > (SLOTS - 1))
		return 0;
	return _inventory[idx];
}
