#include "Animal.hpp"
#include "WrongAnimal.hpp"

void formatAnimalSound(const Animal *animal)
{
	std::cout << animal->getType() << " goes ";
	animal->makeSound();
	std::cout << std::endl;
}

void formatAnimalSound(const WrongAnimal *animal)
{
	std::cout << animal->getType() << " goes ";
	animal->makeSound();
	std::cout << std::endl;
}