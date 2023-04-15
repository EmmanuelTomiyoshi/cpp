#include "Zombie.hpp"

//member functions
Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{

}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//destructor
Zombie::~Zombie()
{
	static int count = 0;
	std::cout	<< "(Destroying Zombie) " << this->name
				<< " [" << count++ << "]" << std::endl;
}

