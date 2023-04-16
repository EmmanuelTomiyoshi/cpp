#include "HumanB.hpp"

void HumanB::attack(void) const
{
	std::cout << _name;
	if (_weapon)
		std::cout << "attacks with their " << _weapon->getType() << std::endl;
	else
	 	std::cout << " is unarmed" << std::endl;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(0)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
