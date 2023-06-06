#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
AForm("Robotomy Request Form", ROBOTOMY_REQUEST_FORM_SIGN, ROBOTOMY_REQUEST_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] default constructor called" << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
AForm("Robotomy Request Form", ROBOTOMY_REQUEST_FORM_SIGN, ROBOTOMY_REQUEST_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] copy constructor called" << std::endl;
	}
	*this = copy;
}

RobotomyRequestForm&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		target = copy.target;
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
AForm("Robotomy Request Form", ROBOTOMY_REQUEST_FORM_SIGN, ROBOTOMY_REQUEST_FORM_EXECUTE, target)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RobotomyRequestForm] target constructor called" << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::canExecute(executor);

	std::cout << "* making drilling noises *" << std::endl;

	static int i = 0;

	if (i++ == 0)
		std::srand(time(NULL));	//set srand only one time

	if (std::rand() % 2 == 1)
		std::cout << target << " has been robotomized succesfully 50\% of the time" << std::endl;
	else
		std::cout << target << " had their robotomy failed" << std::endl;
}