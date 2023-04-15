#include "Zombie.hpp"

int main(void)
{
	Zombie* z = newZombie("Fred");
	z->announce();
	randomChump("Brian");
	delete z;
}