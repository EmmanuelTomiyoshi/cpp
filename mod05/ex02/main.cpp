#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
	{
		try
		{
			ShrubberyCreationForm shrubbery;
		}
		catch (std::exception &e)
		{
			std::cout << "ShrubberyCreationForm: error: " << e.what() << std::endl;
		}
	}
}