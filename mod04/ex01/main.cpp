#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// subject test
	{
		const		Animal *animal[100];
		const		unsigned int count = MAX_SIZE_ANIMAL_OBJECTS;
		std::string *catNames = readAnimalNames("_catNames.txt", count);
		std::string *dogNames = readAnimalNames("_dogNames.txt", count);

		if (catNames == 0 || dogNames == 0)
			return 1;

		int	progress = 0;
		for (unsigned int i = 0; i < 100; ++i)
		{
			if (progress == count) //reset the countdown for other animal object
			{
				progress = 0;
				std::cout << std::endl;
			}

			if (i > count)
			{
				if (i - count < count)
					animal[i] = new Dog(dogNames[i - count]);
				else
					animal[i] = new Dog("Pluto"); //default name if out of range
				++progress;
				update_progress_bar(progress, animal[i]->getType());
			}
			else
			{
				if (i < count)
					animal[i] = new Cat(catNames[i]);
				else
					animal[i] = new Cat("Pandora");
				++progress;
				update_progress_bar(progress, animal[i]->getType());
			}
		}

		std::cout << COLOR_RESET << std::endl << std::endl; //because the last output was green

		formatAnimalCharacter(animal[15]);
		formatAnimalCharacter(animal[23]);
		formatAnimalCharacter(animal[31]);

		std::cout << std::endl;

		formatAnimalCharacter(animal[54]);
		formatAnimalCharacter(animal[58]);
		formatAnimalCharacter(animal[62]);

		std::cout << std::endl;
		
		const Animal *kitty (animal[24]);
		const Animal *puppy (animal[78]);

		formatAnimalCharacter(kitty);
		formatAnimalCharacter(puppy);

		for (unsigned int i = 0; i < 100; ++i)
			delete animal[i];

		delete [] catNames;
		delete [] dogNames;
	}
}