#include "Intern.hpp"
#include "Bureaucrat.hpp"

Intern::Intern(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Intern] default constructor called" << std::endl;
	}
}

Intern::Intern(const Intern &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Intern] copy constructor called" << std::endl;
	}
	*this = copy;
}

Intern&Intern::operator=(const Intern &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Intern] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		//none
	}
	return *this;
}

Intern::~Intern(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Intern] destructor called" << std::endl;
	}
}

AForm *Intern::_newShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::_newRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::_newPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

const char *Intern::FormDoesNotExist::what() const throw()
{
	return "form does not exist";
}

AForm *Intern::makeForm(std::string nameForm, std::string targetForm) const
{
	AForm *form = 0;

	struct
	{
		std::string name;
		AForm *(*func)(const std::string &target);
	} forms[3] = {
		{"shrubbery creation", Intern::_newShrubberyCreationForm},
		{"robotomy request", Intern::_newRobotomyRequestForm},
		{"presidential pardon", Intern::_newPresidentialPardonForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == nameForm)
		{
			form = forms[i].func(targetForm);
			break ;
		}
	}

	if (form)
		std::cout << "Intern created " << form->getName() << std::endl;
	else
		throw FormDoesNotExist();
	return form;
}