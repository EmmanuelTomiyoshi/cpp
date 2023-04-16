#include "Zombie.hpp"

//member functions
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::Zombie()
{

}

//destructor
Zombie::~Zombie()
{
	static int count = 0;
	std::cout	<< "(Destroying Zombie) " << this->_name
				<< " [" << count++ << "]" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}