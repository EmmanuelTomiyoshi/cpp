#ifndef EX01_SCAVTRAP_HPP
#define EX01_SCAVTRAP_HPP

#include "colors.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap //explicit says it is inheriting public of ClapTrap
{
	
	public:
		ScavTrap(void);
		ScavTrap(const std::string &name);
		ScavTrap(const std::string &name, const std::string &color, unsigned int const hp,
				unsigned int const ep, unsigned int const ad);
		ScavTrap(const ScavTrap &copy);
		ScavTrap&operator=(const ScavTrap &copy);
		~ScavTrap(void);

		void attack(const std::string &target);
		void guardGate(void);

		std::ostream&operator<<(std::ostream& os);

	private:
};

std::ostream& operator<<(std::ostream& os, const ScavTrap& obj);

#endif // EX01_SCAVTRAP_HPP