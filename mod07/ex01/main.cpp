#include "Iter.hpp"

int main(void)
{
	std::string array_string[5] = {"ab", "bc", "cd", "de", "ef"};
	int array_int[5] = {0, 1, 2, 3, 4};

	iter(array_string, 5, displayElement);
	iter(array_int, 5, displayElement);
}