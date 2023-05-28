#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("Presidential Pardon Form", SHRUBBERY_CREATION_FORM_SIGN, SHRUBBERY_CREATION_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] default constructor called" << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_FORM_SIGN, SHRUBBERY_CREATION_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] copy constructor called" << std::endl;
	}
	*this = copy;
}

ShrubberyCreationForm&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] assignment copy operator called" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] destructor called" << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_FORM_SIGN, SHRUBBERY_CREATION_FORM_EXECUTE, target)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] target constructor called" << std::endl;
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::string		file = getTarget() + "_shrubbery";
	std::ofstream	output;

	output.open(file.c_str());
	if (output.is_open())
	{
		output << ASCII_TREE;
		if (output.bad())
			std::cout << "[ShrubberyCreationForm] Failed to write to file" << std::endl;
		output.close();
	}
	else
	{
		std::cout << "Could not open file " << file << std::endl;
	}
	output.close();
}