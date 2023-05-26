#include "Form.hpp"

int main ()
{
	{
		Form	formA;
		Form	formB("environment");
		Form	formC("health", 100, 40);
		Form	formD(formC);

		try
		{
			formA.getRequiredGradeToExecute();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}