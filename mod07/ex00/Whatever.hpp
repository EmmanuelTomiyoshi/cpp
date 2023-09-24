#ifndef EX00_WHATEVER_HPP
#define EX00_WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &A, T &B)
{
	T C;

	C = A;
	A = B;
	B = C;
}

template<typename T>
T min(const T &A, T &B)
{
	return (A < B) ? A : B;
}

template<typename T>
T max(const T &A, T &B)
{
	return (A > B) ? A : B;
}

#endif // EX00_WHATEVER_HPP