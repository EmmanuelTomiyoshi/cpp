#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		std::cout << "<TEST 1>" << std::endl;
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "<TEST 2>" << std::endl;
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "<TEST 3>" << std::endl;
		Weapon club = Weapon("crude spiked club");

		HumanB fred("Jim");
		fred.attack();
		club.setType("some other type of club");
		fred.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "<TEST 4>" << std::endl;
		Weapon club = Weapon("Kalashnikov AK-47");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	return 0;
}