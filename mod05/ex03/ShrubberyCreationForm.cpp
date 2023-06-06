#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("Shrubbery Creation Form", SHRUBBERY_CREATION_FORM_SIGN, SHRUBBERY_CREATION_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] default constructor called" << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
AForm("Shrubbery Creation Form", SHRUBBERY_CREATION_FORM_SIGN, SHRUBBERY_CREATION_FORM_EXECUTE, "undefined")
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] copy constructor called" << std::endl;
	}
	*this = copy;
}

ShrubberyCreationForm&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		target = copy.target;
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
AForm("Shrubbery Creation Form", SHRUBBERY_CREATION_FORM_SIGN, SHRUBBERY_CREATION_FORM_EXECUTE, target)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[ShrubberyCreationForm] target constructor called" << std::endl;
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::canExecute(executor);

	std::string		file = getTarget() + "_shrubbery.txt";
	std::ofstream	output;

	output.open(file.c_str());
	if (output.is_open())
	{
		output << ASCII_TREE;
		if (output.bad())
			std::cout << "[ShrubberyCreationForm] Failed to write to file" << std::endl;
	}
	else
	{
		std::cout << "[ShrubberyCreationForm] Could not open file " << file << std::endl;
	}
	output.close();
}