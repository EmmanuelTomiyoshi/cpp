#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), _name("lemur")
{
	std::cout << "[DiamondTrap] Default constructor has been called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_doubleDamage = FragTrap::_doubleDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"),
ScavTrap(), FragTrap(), _name(name)
{
	ClapTrap::_name = name + "_clap_name"; //name of ClapTrap is according to the subject requirements
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_doubleDamage = FragTrap::_doubleDamage;
	ClapTrap::_name.at(0) = std::toupper(ClapTrap::_name.at(0));

	std::cout << "[DiamondTrap] Constructor of " << _name << " has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name, const std::string &color, unsigned int const hp,
unsigned int const ep, unsigned int const ad)
: ClapTrap(name + "_clap_name", color, hp, ep, ad), _name(name)
{
	_doubleDamage = false;
	ClapTrap::_name.at(0) = std::toupper(ClapTrap::_name.at(0));

	std::cout << "[DiamondTrap] " << _color << _name << COLOR_RESET
	<< " has joined the game" << "(HP: " << _hitPoints
	<< " | Energy: " << _energyPoints << " | Attack: "
	<< _attackDamage << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(), ScavTrap(), FragTrap()
{
	*this = copy;
}

DiamondTrap&DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_color = copy._color;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
		_doubleDamage = copy._doubleDamage;
		ClapTrap::_name = copy._name + "_clap_name";
	}
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap] I am: " << _color << _name << COLOR_RESET
	<< " and ClapTrap name is " << ClapTrap::getColor() << ClapTrap::getName()
	<< COLOR_RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	static int new_line = 0;

	if (new_line == 0)
	{
		std::cout << std::endl;
		new_line++;
	}
	std::cout << "[DiamondTrap] " << _color << _name << COLOR_RESET;
	if (isDead())
		std::cout << " is dead";
	else
		std::cout << " has left the game";
	std::cout << std::endl;
}