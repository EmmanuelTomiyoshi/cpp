#include "Array.hpp"

int main(void)
{
	Array<int> 			arrint(2);
	Array<char> 		arrchar(3);
	Array<std::string>	arrstring(4);
	Array<double>		arrdouble(5);

	arrint[0] = 1;
	arrint[1] = 2;

	arrchar[0] = 'a';
	arrchar[1] = 'r';
	arrchar[2] = 'r';

	arrstring[0] = "first";
	arrstring[1] = "second";
	arrstring[2] = "third";
	arrstring[3] = "fourth";

	arrdouble[0] = 42.1;
	arrdouble[1] = 42.2;
	arrdouble[2] = 42.3;
	arrdouble[3] = 42.4;
	arrdouble[4] = 42.5;

	displayElements(arrint, "Int Array:");
	displayElements(arrchar, "Char Array:");
	displayElements(arrstring, "String Array:");
	displayElements(arrdouble, "Double Array:");

	//exception tests
	// arrdouble[-1] = 0;
	// arrstring[10] = "";


}