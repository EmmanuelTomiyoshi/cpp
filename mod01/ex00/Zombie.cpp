#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

Zombie* newZombie( std::string name)
{
	return new Zombie(name);
}

Zombie::~Zombie()
{
	std::cout << "(Destroying Zombie) " << this->name << std::endl;
}

