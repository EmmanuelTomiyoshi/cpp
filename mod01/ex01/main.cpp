#include "Zombie.hpp"

int main(void)
{
	Zombie *z;
	z = zombieHorde(10, "Fred");
	if (!z)
		return (1);
	for(int i = 0; i < 10; i++)
	{
		z[i].announce();
	}
	delete [] z;
}