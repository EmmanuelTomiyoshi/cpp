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
		std::string *catIdeas = readAnimalNames("_catIdeas.txt", count);
		std::string *dogNames = readAnimalNames("_dogNames.txt", count);
		std::string *dogIdeas = readAnimalNames("_dogIdeas.txt", count);

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
				{
					animal[i] = new Dog(dogNames[i - count]);
					reinterpret_cast<const Dog *>(animal[i])->getBrain()->setIdea(i, dogIdeas[i - count]);
				}
				else
				{
					animal[i] = new Dog("Pluto"); //default name if out of range
					reinterpret_cast<const Dog *>(animal[i])->getBrain()->setIdea(i, " probably thinking of eating/sleeping");
				}
				++progress;
				update_progress_bar(progress, animal[i]->getType());
			}
			else
			{
				if (i < count)
				{
					animal[i] = new Cat(catNames[i]);
					reinterpret_cast<const Cat *>(animal[i])->getBrain()->setIdea(i, catIdeas[i]);
				}
				else
				{
					animal[i] = new Cat("Pandora");
					reinterpret_cast<const Cat *>(animal[i])->getBrain()->setIdea(i, " probably thinking of dominating the world");
				}
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

		std::cout << std::endl;

		std::cout << COLOR_BHWHITE << animal[15]->getName() << COLOR_RESET
		<< " thinks:\t" << reinterpret_cast<const Cat *>(animal[15])->getBrain()->getIdea(15) << std::endl;

		std::cout << COLOR_BHWHITE << animal[43]->getName() << COLOR_RESET
		<< " thinks:\t" << reinterpret_cast<const Cat *>(animal[43])->getBrain()->getIdea(43) << std::endl;
	
		std::cout << COLOR_BHWHITE << animal[51]->getName() << COLOR_RESET
		<< " thinks:\t" << reinterpret_cast<const Cat *>(animal[51])->getBrain()->getIdea(51) << std::endl;

		std::cout << COLOR_BHWHITE << animal[98]->getName() << COLOR_RESET
		<< " thinks:\t" << reinterpret_cast<const Cat *>(animal[98])->getBrain()->getIdea(98) << std::endl;

		for (unsigned int i = 0; i < 100; ++i)
			delete animal[i];

		delete [] catNames;
		delete [] catIdeas;
		delete [] dogNames;
		delete [] dogIdeas;
	}
}