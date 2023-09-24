#include "Whatever.hpp"

int main(void)
{			
	int A = 4;
	int B = 10;

	::swap<int>(A, B); //:: means no namespace
	std::cout << "A = " << A << ", B = " << B << std::endl;

	std::cout << "min( A, B ) = " << ::min( A, B ) << std::endl;
	std::cout << "max( A, B ) = " << ::max( A, B ) << std::endl;
}