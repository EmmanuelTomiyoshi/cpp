#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void update_progress_bar(const int progress, const std::string &animal)
{
	std::cout << COLOR_RESET << "\rCreating " << animal
	<< " objects " << COLOR_GREEN << "[";
	int pos = 0;
	for (int i = 0; i < 50; ++i)
	{
		if (pos < progress)
		{
			std::cout << "=";
		}
		else
		{
			std::cout << ".";
		}
		++pos;
	}
	std::cout << "] " << (progress) << "%";
	std::cout.flush();
	clock_t start_time = clock();
	while (clock() < start_time + 8000) { }
}

int main(void)
{
	// subject test
	{
		const		Animal *animal[100];
		const		unsigned int count = 50;
		std::string *catNames = readAnimalNames("catNames.txt", 50);
		std::string *dogNames = readAnimalNames("dogNames.txt", 50);

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
					++progress;
					update_progress_bar(progress, animal[i]->getType());
				}
				else
				{
					animal[i] = new Dog("Pluto"); //default name if out of range
					++progress;
					update_progress_bar(progress, animal[i]->getType());
				}
			}
			else
			{
				if (i < count)
				{
					animal[i] = new Cat(catNames[i]);
					++progress;
					update_progress_bar(progress, animal[i]->getType());
				}
				else
				{
					animal[i] = new Cat("Pandora");
					++progress;
					update_progress_bar(progress, animal[i]->getType());
				}
			}
		}

		std::cout << COLOR_RESET << std::endl; //because the last output was green

		formatAnimalCharacter(animal[15]);
		formatAnimalCharacter(animal[23]);
		formatAnimalCharacter(animal[31]);

		for (unsigned int i = 0; i < 100; ++i)
			delete animal[i];

		delete [] catNames;
		delete [] dogNames;
	}
}