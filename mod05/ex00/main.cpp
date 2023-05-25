#include "Bureaucrat.hpp"

int main ()
{
	//Success
	{
		Bureaucrat example("Bob", 2);

		try
		{
			Bureaucrat a(example);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b = example;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat c("Bob", 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat d;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat f("fred");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << COLOR_BHWHITE << "EXCEPTIONS" << COLOR_RESET << std::endl;

	//exception grade too high
	{
		try
		{
			Bureaucrat a("Karl", 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	//exception grade too low
	{
		try
		{
			Bureaucrat a("Simon", 152);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b("Larry", -8);
			//if you do this to an unsigned short, you'll get an overflow...
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			//...so it will raise a grade is too low exception (USHORT_MAX = 65532)
		}

		try
		{
			Bureaucrat c("Simon", 65533);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << COLOR_BHWHITE << "TESTS WITH INCREMENT/DECREMENT" << COLOR_RESET << std::endl;

	{
		Bureaucrat Louis("Louis", 50);
		Bureaucrat Brandon("Brandon");
		Bureaucrat MaryAnne("Marry Anne", 1);
		Bureaucrat Melissa("Melissa", 3);
		Bureaucrat Paola("Paola", 34);

		std::cout << std::endl << Louis << Brandon << MaryAnne << Melissa << Paola;

		try
		{
			Louis.checkGrade(Louis.getGrade());
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Brandon.decrementGrade();		//too low (151)
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			MaryAnne.incrementGrade();		//too high (0)
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Melissa.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Paola.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}