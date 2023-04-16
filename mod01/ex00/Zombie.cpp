#include "Zombie.hpp"

//member functions
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//destructor
Zombie::~Zombie()
{
	std::cout << "(Destroying Zombie) " << this->_name << std::endl;
}

