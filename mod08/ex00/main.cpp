#include "Easyfind.hpp"

void	readFileAndStoreWords(const std::string &filename, std::vector<std::string> &words)
{
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening the file: " << filename << std::endl;
		return ;
	}

	std::string word;
	while (inputFile >> word)	//reads data from the input stream until it encounters a whitespace character
	{
		words.push_back(word);
	}

	inputFile.close();
}

int main(void)
{
	std::vector<int> vecInt;
	std::vector<double> vecDouble;
	std::vector<std::string> vecString;

	vecInt.reserve(8);
	int result = 1;
	for (size_t i = 0; i < 32; ++i)
	{
		result *= 2;
		vecInt.push_back(result);
	}

	int target = 8;

	try
	{
		std::vector<int>::iterator found = easyfind(vecInt, target);
		// std::vector<int>::const_iterator found = easyfind(vecInt, target);
		std::cout << "Found " << target << " at position " << (found - vecInt.begin()) << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}


	//

	for (std::vector<int>::iterator it = vecInt.begin(); it != vecInt.end(); ++it)
	{
		int position = std::distance(vecInt.begin(), it) + 1;
		std::cout << "Position " << position << ": " << *it << std::endl;
	}

	//some other tests
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::vector<int> vec;

	vec.reserve(64);
	std::cout << "Capacity at beginning is: " << vec.capacity() << std::endl;

	if (vec.empty())
		std::cout << "Vector is empty" << std::endl;
	else
		std::cout << "Vector is not empty" << std::endl;

	for (int i = 0; i < 256; ++i)
	{
		vec.push_back(std::rand());
	}
	std::cout << "Capacity at end is: " << vec.capacity() << std::endl;

	std::cout << "Accessing random value, at position 100th: " << vec[100] << std::endl;


	std::vector<std::string> professions;

	readFileAndStoreWords("professions.txt", professions);

	//shuffles the vector
	std::random_shuffle(professions.begin(), professions.end());
	std::cout << professions[4];
	std::cout << std::endl;
}

