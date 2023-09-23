#ifndef EX02_RealType_HPP
#define EX02_RealType_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#include "colors.hpp"

class Base {

	public:
		virtual ~Base(void){};
};

class A : public Base
{
	public:
		A(){std::cout << "Called A subclass" << std::endl;}
};

class B : public Base
{
	public:
		B(){std::cout << "Called B subclass" << std::endl;}
};

class C : public Base
{
	public:
		C(){std::cout << "Called C subclass" << std::endl;}
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif // EX02_RealType_HPP