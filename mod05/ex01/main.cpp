#include "Bureaucrat.hpp"

int main ()
{
	{
		Bureaucrat	MaryAnne("Marry Anne", 1);
		Bureaucrat	Anthony("Albert", 25);
		Bureaucrat	Paola("Paola", 34);
		Bureaucrat	Louis("Louis", 50);
		Bureaucrat 	Brandon("Brandon");
		Form		standard;
		Form		formA;
		Form		formB("Environment form");
		Form		formC("Health form", 25, 10);
		Form		formD(formC);

		std::cout << std::endl;

		std::cout << formA << formB << formC << formD;

		standard.formatTableHeader();
		formA.formatTable();
		formB.formatTable();
		formC.formatTable();
		formD.formatTable();

		try
		{
			MaryAnne.signForm(formC);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Anthony.signForm(formC);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Paola.signForm(formC);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

			std::cout << std::endl;

		std::cout << formA << formB << formC << formD;

		standard.formatTableHeader();
		formA.formatTable();
		formB.formatTable();
		formC.formatTable();
		formD.formatTable();

		std::cout << std::endl;
	}

	//trying to create a form with high or low grade
	{
		try
		{
			Form standard("Standard", Bureaucrat::_highestPossibleGrade - 1, 50);
		}
		catch (std::exception &e)
		{
			std::cout << "Form: error: " << e.what() << std::endl;
		}

		try
		{
			Form standard("Standard", Bureaucrat::_lowestPossibleGrade + 1, 50);
		}
		catch (std::exception &e)
		{
			std::cout << "Form: error: " << e.what() << std::endl;
		}
	}
}