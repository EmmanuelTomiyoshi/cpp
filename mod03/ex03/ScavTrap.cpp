#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "[ScavTrap] Default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap()
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_doubleDamage = false;
	_name.at(0) = std::toupper(_name.at(0));
	std::cout << "[ScavTrap] Constructor of " << _name << " has been called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name, const std::string &color, unsigned int const hp,
unsigned int const ep, unsigned int const ad) : ClapTrap()
{
	_name = name;
	_color = color;
	_hitPoints = hp;
	_energyPoints = ep;
	_attackDamage = ad;
	_doubleDamage = false;
	_name.at(0) = std::toupper(_name.at(0));

	std::cout << "[ScavTrap] " << _color << _name << COLOR_RESET
	<< " has joined the game" << "(HP: " << _hitPoints
	<< " | Energy: " << _energyPoints << " | Attack: "
	<< _attackDamage << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap()
{
	*this = copy;
}

ScavTrap&ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_color = copy._color;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
		_doubleDamage = copy._doubleDamage;
	}
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (isDead())
		return ;

	if (_energyPoints == 0)
	{
		std::cout << "[ScavTrap] " << _color << _name
		<< COLOR_RESET << " has no energy points to attack " << target
		<< std::endl;
		return ;
	}
	std::cout << "[ScavTrap] " << _color << _name <<
	COLOR_RESET << " attacks " << target << ", causing " << _attackDamage
	<< " points of damage." << std::endl;

	_energyPoints--;
}

void ScavTrap::guardGate(void)
{
	if (isDead())
		return ;

	std::cout << "[ScavTrap] " << _color << _name
	<< COLOR_RESET << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap] " << _color << _name
	<< COLOR_RESET << " has left the game" << std::endl;
}