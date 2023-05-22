#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << std::endl;
	//subject test
	{
		const Animal* meta = new Animal();
		const Animal* i = new Cat("Garfield");
		const Animal* j = new Dog("Beethoven");

		std::cout << std::endl;

		formatAnimalSound(i);
		formatAnimalSound(j);

		std::cout << std::endl;

		delete meta;
		delete i;
		delete j;
	}

	//wrongcat and wronganimalia
	{

		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat("Pluto");

		std::cout << std::endl;

		formatAnimalSound(i);

		std::cout << std::endl;

		delete meta;
		delete i;
	}
}