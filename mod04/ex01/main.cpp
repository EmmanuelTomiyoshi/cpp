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
		const	Animal *animal[100];
		int		progress = 0;

		for (int i = 0; i < 100; ++i)
		{
			if (progress == 50) //reset the countdown for other animal object
			{
				progress = 0;
				std::cout << std::endl;
			}
			if (i > 50)
			{
				animal[i] = new Dog("Scooby-Doo");
				++progress;
				update_progress_bar(progress + 1, animal[i]->getType());
			}
			else
			{
				animal[i] = new Cat("Garfield");
				++progress;
				update_progress_bar(progress, animal[i]->getType());
			}
		}

		std::cout << COLOR_RESET << std::endl; //because the last output was green

		for (int i = 0; i < 100; i++)
			delete animal[i];
		
		// std::cout << animal[60]->getName() << std::endl;
		// std::cout << animal[60]->getType() << std::endl;
		// animal[60]->makeSound();
	}
}