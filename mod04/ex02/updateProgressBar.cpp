#include "AAnimal.hpp"

void update_progress_bar(const int progress, const std::string &animal)
{
	std::cout << COLOR_RESET << "\rCreating " << animal
	<< " objects " << COLOR_GREEN << "[";
	int pos = 0;
	for (int i = 0; i < MAX_SIZE_ANIMAL_OBJECTS; ++i)
	{
		if (pos < progress)
			std::cout << "=";
		else
			std::cout << ".";
		++pos;
	}
	int percentage = static_cast<int>((static_cast<double>(progress) / MAX_SIZE_ANIMAL_OBJECTS) * 100);
    std::cout << "] " << percentage << "%";
	std::cout.flush();
	clock_t start_time = clock();
	while (clock() < start_time + 8000) { }
}
