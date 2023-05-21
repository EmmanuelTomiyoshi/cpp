#ifndef EX03_DIAMONDTRAP_HPP
#define EX03_DIAMONDTRAP_HPP

#include "colors.hpp"
#include "FragTrap.hpp"
#include <iostream>

//inherits from both, since each of them is declared as virtual
class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string &name);
		DiamondTrap(const std::string &name, const std::string &color, unsigned int const hp,
				unsigned int const ep, unsigned int const ad);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap&operator=(const DiamondTrap &copy);
		~DiamondTrap(void);

		void whoAmI(void);
		using ScavTrap::attack; //using because of the ambiguity, since we already have
								//a public attack() on the superclasses Scav, Frag, and Clap

		std::ostream&operator<<(std::ostream& os);

	protected:
		using FragTrap::_hitPoints;		//"using" for when the variable has the same name,
		using FragTrap::_attackDamage;  //because it could lead to ambiguity.
		using ScavTrap::_energyPoints;

	private:
		std::string _name;
};

std::ostream& operator<<(std::ostream& os, const DiamondTrap& obj);

#endif // EX03_DIAMONDTRAP_HPP