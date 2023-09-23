#include "RealType.hpp"

Base *generate(void)
{
	int random;

	std::srand(time(NULL));

	random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	static int i = 0;
	if (i == 0)	//just to not repeat the message, as I'm subcalling this function.
		std::cout << "Read by pointer: " << std::endl;

	if (dynamic_cast<A*>(p))
		std::cout << "The type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The type is C" << std::endl;
	else
		std::cout << "The type is NULL" << std::endl;

	i++;

}

void identify(Base &p)
{
	std::cout << "Read by reference: " << std::endl;
	identify(&p);
	// try
	// {
	// 	(void) dynamic_cast<A&>(p);
	// 	std::cout << "The type is A" << std::endl;
	// }
	// catch (std::exception &e){}
	// try
	// {
	// 	(void) dynamic_cast<B&>(p);
	// 	std::cout << "The type is B" << std::endl;
	// }
	// catch (std::exception &e){}
	// try
	// {
	// 	(void) dynamic_cast<C&>(p);
	// 	std::cout << "The type is C" << std::endl;
	// }
	// catch (std::exception &e){}
}
