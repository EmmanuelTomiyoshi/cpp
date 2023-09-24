#ifndef EX01_ITER_HPP
#define EX01_ITER_HPP

#include <iostream>

template <typename T>	//argument
void iter(T *array_ref, size_t n, void (*func)(T&))
{
	if (!array_ref)
		return ;
	for (size_t i = 0; i < n; i++)
	{
		func(array_ref[i]);
	}
}

template <typename T>	//function template
void displayElement(T element)
{
	std::cout << element << std::endl;
}


#endif // EX01_ITER_HPP