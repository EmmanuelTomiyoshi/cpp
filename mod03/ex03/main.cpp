#include "DiamondTrap.hpp"

int main(void)
{
	//name, color name, hp, energy, attack damage
	std::cout << COLOR_BHWHITE << "CONSTRUCTORS" << COLOR_RESET << std::endl;
	FragTrap 	Pancho("pancho", COLOR_BHRED, 26, 6, 10);
	FragTrap 	Willie("Willie", COLOR_BHGREEN, 14, 10, 4);
	FragTrap 	Karl("Karl", COLOR_BHBLUE, 20, 8, 7);
	FragTrap 	Ted("Ted", COLOR_BHMAGENTA, 18, 4, 6);
	FragTrap 	Hector("Hector", COLOR_BHYELLOW, 30, 2, 8);
	ScavTrap 	Horst("horst", COLOR_BHCYAN, 19, 12, 5);
	FragTrap 	Clone(Pancho);
	DiamondTrap MaryAnne("Mary Anne", COLOR_BHMAGENTA, 35, 6, 20);

	std::cout << std::endl << COLOR_BHWHITE << "THE FIGHT" << COLOR_RESET << std::endl;

	//KILL
	{
		Hector.attack(Willie.getName());
		Willie.takeDamage(8);
		Hector.attack(Willie.getName());
		Willie.takeDamage(8);
	}

	//NO ENERGY POINTS
	{
		Hector.attack(Ted.getName());
		Hector.beRepaired(6);
	}

	//ATTACK
	{
		Pancho.attack(Karl.getName());
		Karl.attack(Horst.getName());
	}

	//TAKE NO DAMAGE
	{
		Karl.takeDamage(0);
		Horst.takeDamage(7);
	}

	//PLAYER IS DEAD (no side effects)
	{
		Willie.attack(Hector.getName());
		Willie.takeDamage(4);
		Willie.beRepaired(6);
		Horst.beRepaired(10);
	}

	//HEAL
	{
		Ted.beRepaired(4);
		Karl.beRepaired(10);
	}

	std::cout << std::endl << COLOR_BHWHITE << "HIGH FIVE" << COLOR_RESET << std::endl;

	//HIGHFIVESGUYS()
	{
		Ted.highFivesGuys();
		Pancho.highFivesGuys();
		Willie.highFivesGuys();
		Clone.setName("Pancho \"copy\" clone");
		Clone.highFivesGuys();
		Clone = Hector;
		Clone.setName("Hector \"copy assignment\" clone");
		Clone.highFivesGuys();
	}

	//Here's the diamond problem
	{
		std::cout << std::endl << COLOR_BHWHITE << "DIAMOND PROBLEM" << COLOR_RESET << std::endl;
		MaryAnne.attack("Hector \"copy\" clone"); //attack is from ScavTrap
		Clone.takeDamage(20);
		MaryAnne.attack("Hector \"copy\" clone");
		Clone.takeDamage(20);

		Pancho.attack(MaryAnne.getName());
		MaryAnne.takeDamage(10);
	}

	//WHOAMI()
	{
		std::cout << std::endl << COLOR_BHWHITE << "WHO AM I" << COLOR_RESET << std::endl;
		MaryAnne.whoAmI();
	}

	std::cout << std::endl << COLOR_BHWHITE << "DESTRUCTORS" << COLOR_RESET;

	return 0;
}