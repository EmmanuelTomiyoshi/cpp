#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon &w);
		void attack(void) const;
};

#endif