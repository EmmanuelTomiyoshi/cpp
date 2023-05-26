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
			Bureaucrat c("Natalia", 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat d;	//still, doesn't need a try catch because we're not setting the grade
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat f("Fred"); //nor this one
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
			Bureaucrat a("John", 152);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b("Larry", -8);
			//if you do this to an size_t, you'll get an overflow...
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			//...so it will raise a "grade is too low" exception (USHORT_MAX = 65532)
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
		Bureaucrat MaryAnne("Marry Anne", 1);
		Bureaucrat Albert("Albert", 3);
		Bureaucrat Paola("Paola", 34);
		Bureaucrat Louis("Louis", 50);
		Bureaucrat Brandon("Brandon");
		Bureaucrat standard;		//just for the Table Header

		std::cout << std::endl;

		standard.formatTableHeader();

		MaryAnne.formatTable();
		Albert.formatTable();
		Paola.formatTable();
		Louis.formatTable();
		Brandon.formatTable();

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
			Albert.incrementGrade();
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

		std::cout << std::endl;
	}
}