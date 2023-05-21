#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "[ClapTrap] Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name),
_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	_name.at(0) = std::toupper(_name.at(0));
	std::cout << "[ClapTrap] Constructor of " << _name << " has been called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const std::string &color, unsigned int const hp,
unsigned int const ep, unsigned int const ad) : _name(name), _color(color),
_hitPoints(hp), _energyPoints(ep), _attackDamage(ad)
{
	_name.at(0) = std::toupper(_name.at(0));

	std::cout << "[ClapTrap] " << _color << _name << COLOR_RESET
	<< " has joined the game" << "(HP: " << _hitPoints
	<< " | Energy: " << _energyPoints << " | Attack: "
	<< _attackDamage << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap&ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_color = copy._color;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return *this;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

void ClapTrap::setName(const std::string &name)
{
	_name = name;
}

void ClapTrap::attack(const std::string &target)
{
	if (isDead())
		return ;

	if (_energyPoints == 0)
	{
		std::cout << "[ClapTrap] " << _color << _name
		<< COLOR_RESET << " has no energy points to attack " << target
		<< std::endl;
		return ;
	}
	std::cout << "[ClapTrap] " << _color << _name <<
	COLOR_RESET << " attacks " << target << ", causing " << _attackDamage
	<< " points of damage." << std::endl;

	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead())
		return ;

	std::cout << "[ClapTrap] " << _color << _name << COLOR_RESET;

	if (amount == 0)
	{
		std::cout << " hasn\'t taken any damage, chiuf!" << std::endl;
		return ;
	}

	if (amount > _hitPoints)
	{
		std::cout << " has died [" << _hitPoints;
		_hitPoints = 0;
		std::cout << " -> " << _hitPoints << " HP]" << std::endl;
		return ;
	}

	std::cout <<" has taken -" << amount << " of damage [" << _hitPoints;
	
	_hitPoints -= amount;
	std::cout << " -> " << _hitPoints << " HP]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead())
		return ;

	if (_energyPoints == 0)
	{
		std::cout << "[ClapTrap] " << _color << _name
		<< COLOR_RESET << " has no energy points to heal itself."
		<< std::endl;
		return ;
	}
	std::cout << "[ClapTrap] " << _color << _name << COLOR_RESET
	<< " has healed itself +" << amount << " [" << _hitPoints;

	_hitPoints += amount;
	std::cout << " -> " << _hitPoints << " HP]" << std::endl;

	_energyPoints--;
}

bool ClapTrap::isDead(void)
{
	if (_hitPoints == 0)
		return true;
	return false;
}

int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

void ClapTrap::setHitPoints(const unsigned int hp)
{
	_hitPoints = hp;
}

void ClapTrap::setEnergyPoints(const unsigned int ep)
{
	_energyPoints = ep;
}

void ClapTrap::setAttackDamage(const unsigned int ad)
{
	_attackDamage = ad;
}

ClapTrap::~ClapTrap(void)
{
	static int new_line = 0;

	if (new_line == 0)
	{
		std::cout << std::endl;
		new_line++;
	}
	std::cout << "[ClapTrap] " << _color << _name
	<< COLOR_RESET << " has left the game" << std::endl;
}