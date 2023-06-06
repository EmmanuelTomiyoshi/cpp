#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{
	std::cout << COLOR_BHWHITE "INTERN TESTS" COLOR_RESET << std::endl;

	//Shrubbery creation
	Intern		internA;
	AForm		*formA = 0;
	Bureaucrat	bureaucratA("John", 5);

	try
	{
		formA = internA.makeForm("shrubbery creation", bureaucratA.getName());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: exception: " << e.what() << std::endl;
	}

	//Robotomy request
	Intern		internB;
	AForm		*formB = 0;
	Bureaucrat	bureaucratB("Albert", 5);

	try
	{
		formB = internB.makeForm("robotomy request", bureaucratB.getName());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: exception: " << e.what() << std::endl;
	}

	//Presidential pardoon
	Intern		internC;
	AForm		*formC = 0;
	Bureaucrat	bureaucratC("Mary", 5);

	try
	{
		formC = internC.makeForm("presidential pardon", bureaucratC.getName());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: exception: " << e.what() << std::endl;
	}

	//error 
	Intern		internD;
	AForm		*formD = 0;
	Bureaucrat	bureaucratD("David", 5);

	try
	{
		formD = internD.makeForm("a random form", bureaucratD.getName());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: exception: " << e.what() << std::endl;
	}

	delete formA;
	delete formB;
	delete formC;
	delete formD;
}
