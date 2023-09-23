#include "RealType.hpp"

int main(void)
{
	Base *random = generate();
	Base &b = *random;

	identify(random);
	identify(b);
	// identify(NULL);
	delete random;
}
