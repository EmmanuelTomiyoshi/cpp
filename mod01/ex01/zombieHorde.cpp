#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *z;

	if (N <= 0 || N > 100)
	{
		std::cout	<< "Number must be between 1 - 100"
					<< std::endl;
		return (NULL);
	}

	z = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		z[i].setName(name);
		std::cout << "Created Zombie " << name << " [" << i << "]" << std::endl;
	}
	return (z);
}
