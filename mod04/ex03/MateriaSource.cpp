#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _inventory()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[MateriaSource]" << " default constructor called" << std::endl;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) : _inventory()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[MateriaSource]" << " copy constructor called" << std::endl;
	}
	*this = copy;
}

MateriaSource&MateriaSource::operator=(const MateriaSource &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[MateriaSource]" << " copy assignment operator called" << std::endl;
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
				_inventory[i] = copy._inventory[i]->clone();
		}
	}

	return *this;
}

MateriaSource::~MateriaSource(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[MateriaSource]" << " default destructor called" << std::endl;
	}
	for (int i = 0; i < SLOTS; i++)
		delete _inventory[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < SLOTS; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "[MateriaSource]" << " succesfully learned at slot ["
			<< i << "]" << std::endl;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < SLOTS; i++)
	{
		//copy of the Materia previously learned by the MateriaSource, type must be equal
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return 0; // therefore, return 0 if type is unknown
}

const AMateria *MateriaSource::getMateria(int idx) const
{
	if (idx < 0 || idx > (SLOTS - 1))
		return 0;
	return _inventory[idx];
}