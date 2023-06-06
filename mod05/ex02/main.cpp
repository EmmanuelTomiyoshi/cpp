#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testsShrubbery(void)
{
	{
		std::cout << COLOR_RED "#1" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				Fred("Fred", 138);
			ShrubberyCreationForm	shrubbery(Fred.getName());
			
			shrubbery.execute(Fred);
		}
		catch (std::exception &e)
		{
			std::cout << "ShrubberyCreationForm: error: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#2" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				Fred("Fred", 150);
			ShrubberyCreationForm	shrubbery(Fred.getName());

			Fred.signForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#3" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				Fred("Fred", 145);
			ShrubberyCreationForm	shrubbery(Fred.getName());

			Fred.signForm(shrubbery);
			shrubbery.execute(Fred);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#4" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				Fred("Fred", 0);
			ShrubberyCreationForm	shrubbery(Fred.getName());
			Fred.signForm(shrubbery);
			shrubbery.execute(Fred);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_GREEN "#5" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				Fred("Fred", 120);
			ShrubberyCreationForm	shrubbery(Fred.getName());

			Fred.signForm(shrubbery);
			shrubbery.execute(Fred);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	testsRobotomy(void)
{
	{
		std::cout << COLOR_RED "#1" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				John("John", 64);
			RobotomyRequestForm		robotomy(John.getName());
			
			robotomy.execute(John);
		}
		catch (std::exception &e)
		{
			std::cout << "RobotomyRequestForm: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#2" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				John("John", 150);
			RobotomyRequestForm		robotomy(John.getName());

			John.signForm(robotomy);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#3" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				John("John", 46);
			RobotomyRequestForm		robotomy(John.getName());

			John.signForm(robotomy);
			robotomy.execute(John);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#4" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				John("John", 0);
			RobotomyRequestForm		robotomy(John.getName());

			John.signForm(robotomy);
			robotomy.execute(John);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_GREEN "#5" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				John("John", 44);
			RobotomyRequestForm		robotomy(John.getName());

			John.signForm(robotomy);
			robotomy.execute(John);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_GREEN "#6" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				John("John", 44);
			RobotomyRequestForm		robotomy(John.getName());

			John.signForm(robotomy);
			robotomy.execute(John);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_GREEN "#7" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat				John("John", 44);
			RobotomyRequestForm		robotomy(John.getName());

			John.signForm(robotomy);
			robotomy.execute(John);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	testsPresidential(void)
{
	{
		std::cout << COLOR_RED "#1" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat					Mary("Mary", 64);
			PresidentialPardonForm		presidential(Mary.getName());
			
			presidential.execute(Mary);
		}
		catch (std::exception &e)
		{
			std::cout << "Presidential Pardon Form: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#2" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat					Mary("Mary", 150);
			PresidentialPardonForm		presidential(Mary.getName());

			Mary.signForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#3" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat					Mary("Mary", 20);
			PresidentialPardonForm		presidential(Mary.getName());

			Mary.signForm(presidential);
			presidential.execute(Mary);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_RED "#4" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat					Mary("Mary", 0);
			PresidentialPardonForm		presidential(Mary.getName());
			Mary.signForm(presidential);
			presidential.execute(Mary);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << COLOR_GREEN "#5" COLOR_RESET << std::endl;
		try
		{
			Bureaucrat					Mary("Mary", 2);
			PresidentialPardonForm		presidential(Mary.getName());

			Mary.signForm(presidential);
			presidential.execute(Mary);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

int main ()
{
	std::cout << COLOR_BHWHITE "SHRUBBERY TESTS" COLOR_RESET << std::endl;
	testsShrubbery();
	std::cout << std::endl << COLOR_BHWHITE "ROBOTOMY TESTS" COLOR_RESET << std::endl;
	testsRobotomy();
	std::cout << std::endl << COLOR_BHWHITE "PRESIDENTIAL TESTS" COLOR_RESET << std::endl;
	testsPresidential();

	//additional tests with Bureaucrat::executeForm()
	Bureaucrat					b("Mary", 2);
	PresidentialPardonForm		ppf(b.getName());
	b.executeForm(ppf);
	b.signForm(ppf);
	b.executeForm(ppf);
}