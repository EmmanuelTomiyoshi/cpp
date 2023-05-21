#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "[FragTrap] Default constructor has been called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_name.at(0) = std::toupper(_name.at(0));
	std::cout << "[FragTrap] Constructor of " << _name << " has been called!" << std::endl;
}

FragTrap::FragTrap(const std::string &name, const std::string &color, unsigned int const hp,
unsigned int const ep, unsigned int const ad) : ClapTrap(name, color, hp, ep, ad)
{
	_name.at(0) = std::toupper(_name.at(0));

	std::cout << "[FragTrap] " << _color << _name << COLOR_RESET
	<< " has joined the game" << "(HP: " << _hitPoints
	<< " | Energy: " << _energyPoints << " | Attack: "
	<< _attackDamage << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap()
{
	*this = copy;
}

FragTrap&FragTrap::operator=(const FragTrap &copy)
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

void FragTrap::attack(const std::string &target)
{
	if (isDead())
		return ;

	if (_energyPoints == 0)
	{
		std::cout << "[FragTrap] " << _color << _name
		<< COLOR_RESET << " has no energy points to attack " << target
		<< std::endl;
		return ;
	}
	std::cout << "[FragTrap] " << _color << _name <<
	COLOR_RESET << " attacks " << target << ", causing " << _attackDamage
	<< " points of damage." << std::endl;

	_energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	if (isDead())
	{
		std::cout << "[FragTrap] " << _color << _name
		<< COLOR_RESET << " may rest in peace, but no one can resist to a high five 👏"
		<< std::endl;
		return ;
	}

	std::cout << "[FragTrap] " << _color << _name << COLOR_RESET
	<< " gives a high five. Who\'s joining in? 👋" << std::endl;
}

FragTrap::~FragTrap(void)
{
	static int new_line = 0;

	if (new_line == 0)
	{
		std::cout << std::endl;
		new_line++;
	}
	std::cout << "[FragTrap] " << _color << _name << COLOR_RESET;
	if (isDead())
		std::cout << " is dead";
	else
		std::cout << " has left the game";
	std::cout << std::endl;
}