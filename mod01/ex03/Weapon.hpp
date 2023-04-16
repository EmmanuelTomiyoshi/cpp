#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string _type;

	public:
		std::string const &getType(void) const; //last "const" assures it can not modify any member
		void setType(std::string const &type);
		Weapon(std::string type);
};

#endif