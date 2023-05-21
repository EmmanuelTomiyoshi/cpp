#ifndef EX03_DIAMONDTRAP_HPP
#define EX03_DIAMONDTRAP_HPP

#include "colors.hpp"
#include "FragTrap.hpp"
#include <iostream>

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
		using ScavTrap::attack;

		std::ostream&operator<<(std::ostream& os);

	protected:
		using FragTrap::_hitPoints;		//"using" for when the variable has the same name,
		using FragTrap::_attackDamage;  //because it could lead to ambiguity. But, anyways,
		using ScavTrap::_energyPoints;  //you can't access it without this clearly "using".

	private:
		std::string _name;

};

std::ostream& operator<<(std::ostream& os, const DiamondTrap& obj);

#endif // EX03_DIAMONDTRAP_HPP