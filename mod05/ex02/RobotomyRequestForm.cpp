#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
AForm("Presidential Pardon Form", ROBOTOMY_REQUEST_FORM_SIGN, ROBOTOMY_REQUEST_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] default constructor called" << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_FORM_SIGN, ROBOTOMY_REQUEST_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] copy constructor called" << std::endl;
	}
	*this = copy;
}

RobotomyRequestForm&RobotomyRequestForm::operator=(const RobotomyRequestForm &)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] assignment copy operator called" << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] destructor called" << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_FORM_SIGN, ROBOTOMY_REQUEST_FORM_EXECUTE, target)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] target constructor called" << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	if (clock() % 2 == 0)
	{
		std::cout << getTarget() << " has been robotomized succesfully 50\% of the time" << std::endl;
	}
	else
	{
		std::cout << "The robotomy of " << getTarget() << " has failed" << std::endl;
	}
}