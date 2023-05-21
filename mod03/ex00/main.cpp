#include "ClapTrap.hpp"

int main(void)
{
	//name, color name, hp, energy, attack damage
	std::cout << COLOR_BHWHITE << "CONSTRUCTORS" << COLOR_RESET << std::endl;
	ClapTrap Hector("Hector", COLOR_BHYELLOW, 30, 2, 8);
	ClapTrap Pancho("pancho", COLOR_BHRED, 26, 6, 10);
	ClapTrap Karl("Karl", COLOR_BHCYAN, 20, 8, 7);
	ClapTrap Ted("Ted", COLOR_BHMAGENTA, 18, 4, 6);
	ClapTrap Willie("Willie", COLOR_BHGREEN, 14, 10, 4);

	std::cout << std::endl << COLOR_BHWHITE << "THE FIGHT" << COLOR_RESET << std::endl;
	//KILL
	Hector.attack(Willie.getName());
	Willie.takeDamage(8);
	Hector.attack(Willie.getName());
	Willie.takeDamage(8);

	//NO ENERGY POINTS
	Hector.attack(Ted.getName());
	Hector.beRepaired(6);

	//ATTACK
	Pancho.attack(Karl.getName());

	//TAKE NO DAMAGE
	Karl.takeDamage(0);

	//PLAYER IS DEAD (no side effects)
	Willie.attack(Hector.getName());
	Willie.takeDamage(4);
	Willie.beRepaired(6);

	//HEAL
	Ted.beRepaired(4);

	std::cout << std::endl << COLOR_BHWHITE << "DESTRUCTORS" << COLOR_RESET;

	return 0;
}