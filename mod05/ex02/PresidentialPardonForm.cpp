#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("Presidential Pardon Form", PRES_PARDON_FORM_SIGN, PRES_PARDON_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PresidentialPardonForm] default constructor called" << std::endl;
	}
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
AForm("PresidentialPardonForm", PRES_PARDON_FORM_SIGN, PRES_PARDON_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PresidentialPardonForm] copy constructor called" << std::endl;
	}
	*this = copy;
}

PresidentialPardonForm&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PresidentialPardonForm] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		target = copy.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PresidentialPardonForm] destructor called" << std::endl;
	}
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("PresidentialPardonForm", PRES_PARDON_FORM_SIGN, PRES_PARDON_FORM_EXECUTE, target)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[PresidentialPardonForm] target constructor called" << std::endl;
	}
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::canExecute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}