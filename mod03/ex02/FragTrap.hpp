#ifndef EX02_FRAGTRAP_HPP
#define EX02_FRAGTRAP_HPP

#include "colors.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap //explicit says it is inheriting public of ClapTrap
{
	
	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const std::string &name, const std::string &color, unsigned int const hp,
				unsigned int const ep, unsigned int const ad);
		FragTrap(const FragTrap &copy);
		FragTrap&operator=(const FragTrap &copy);
		~FragTrap(void);

		void attack(const std::string &target);
		void highFivesGuys(void);

		std::ostream&operator<<(std::ostream& os);

	private:
};

std::ostream& operator<<(std::ostream& os, const FragTrap& obj);

#endif // EX02_FRAGTRAP_HPP