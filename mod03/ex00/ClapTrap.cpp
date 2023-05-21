#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "[ClapTrap] Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name),
_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	this->_name.at(0) = std::toupper(this->_name.at(0));
	std::cout << "[ClapTrap] Constructor of " << this->_name << " has been called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const std::string &color, unsigned int const hp,
unsigned int const ep, unsigned int const ad) : _name(name), _color(color),
_hitPoints(hp), _energyPoints(ep), _attackDamage(ad)
{
	this->_name.at(0) = std::toupper(this->_name.at(0));

	std::cout << "[ClapTrap] " << this->_color << this->_name << COLOR_RESET
	<< " has joined the game" << "(HP: " << this->_hitPoints
	<< " | Energy: " << this->_energyPoints << " | Attack: "
	<< this->_attackDamage << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap&ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_color = copy._color;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

void ClapTrap::setName(const std::string &name)
{
	this->_name = name;
}

void ClapTrap::attack(const std::string &target)
{
	if (isDead())
		return ;

	if (this->_energyPoints == 0)
	{
		std::cout << "[ClapTrap] " << this->_color << this->_name
		<< COLOR_RESET << " has no energy points to attack " << target
		<< std::endl;
		return ;
	}
	std::cout << "[ClapTrap] " << this->_color << this->_name <<
	COLOR_RESET << " attacks " << target << ", causing " << this->_attackDamage
	<< " points of damage." << std::endl;

	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead())
		return ;

	std::cout << "[ClapTrap] " << this->_color << this->_name << COLOR_RESET;

	if (amount == 0)
	{
		std::cout << " hasn\'t taken any damage, chiuf!" << std::endl;
		return ;
	}

	if (amount > this->_hitPoints)
	{
		std::cout << " has died [" << this->_hitPoints;
		this->_hitPoints = 0;
		std::cout << " -> " << this->_hitPoints << " HP]" << std::endl;
		return ;
	}

	std::cout <<" has taken -" << amount << " of damage [" << this->_hitPoints;
	
	this->_hitPoints -= amount;
	std::cout << " -> " << this->_hitPoints << " HP]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead())
		return ;

	if (this->_energyPoints == 0)
	{
		std::cout << "[ClapTrap] " << this->_color << this->_name
		<< COLOR_RESET << " has no energy points to heal itself."
		<< std::endl;
		return ;
	}
	std::cout << "[ClapTrap] " << this->_color << this->_name << COLOR_RESET
	<< " has healed itself +" << amount << " [" << this->_hitPoints;

	this->_hitPoints += amount;
	std::cout << " -> " << this->_hitPoints << " HP]" << std::endl;

	this->_energyPoints--;
}

bool ClapTrap::isDead(void)
{
	if (this->_hitPoints == 0)
		return true;
	return false;
}

int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

void ClapTrap::setHitPoints(const unsigned int hp)
{
	this->_hitPoints = hp;
}

void ClapTrap::setEnergyPoints(const unsigned int ep)
{
	this->_energyPoints = ep;
}

void ClapTrap::setAttackDamage(const unsigned int ad)
{
	this->_attackDamage = ad;
}

ClapTrap::~ClapTrap(void)
{
	static int new_line = 0;

	if (new_line == 0)
	{
		std::cout << std::endl;
		new_line++;
	}
	std::cout << "[ClapTrap] " << this->_color << this->_name
	<< COLOR_RESET << " has left the game" << std::endl;
}