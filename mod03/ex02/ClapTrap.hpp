#ifndef EX00_CLAPTRAP_HPP
#define EX00_CLAPTRAP_HPP

#include "colors.hpp"
#include <iostream>

class ClapTrap {
	
	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const std::string &name, const std::string &color, unsigned int const hp,
				unsigned int const ep, unsigned int const ad);
		ClapTrap(const ClapTrap &copy);
		ClapTrap&operator=(const ClapTrap &copy);
		~ClapTrap(void);

		int getHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getAttackDamage(void) const;
		void setHitPoints(unsigned int const hp);
		void setEnergyPoints(unsigned int const ep);
		void setAttackDamage(unsigned int const ad);

		std::string getName(void) const;
		void setName(const std::string &name);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		bool isDead(void);

		std::ostream&operator<<(std::ostream& os);

	protected:
		std::string		_name;
		std::string		_color;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

};

std::ostream& operator<<(std::ostream& os, const ClapTrap& obj);

#endif // EX00_CLAPTRAP_HPP