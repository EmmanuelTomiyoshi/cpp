#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <stdexcept>

#include <fstream>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	std::vector<int>::iterator it = std::find(container.begin(), container.end(), value);

	if (it != container.end())
		return it;
	else
		throw std::runtime_error("Value not found in the container.");
}

template<typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	std::vector<int>::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it != container.end())
		return it;
	else
		throw std::runtime_error("Value not found in the container.");
}

#endif // EX00_EASYFIND_HPP