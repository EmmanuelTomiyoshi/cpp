#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) :
target("nobody"),
_name("standard form"), _isSigned(false),
_requiredGradeToSign(Bureaucrat::_lowestPossibleGrade),
_requiredGradeToExecute(Bureaucrat::_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AForm] default constructor called" << std::endl;
	}
}

AForm::AForm(const AForm &copy) :
_name(copy.getName()), _isSigned(copy.getIsSigned()),
_requiredGradeToSign(copy.getRequiredGradeToSign()),
_requiredGradeToExecute(copy.getRequiredGradeToExecute())
{
	//we copy the properties at initialization, since they are constant
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AForm] copy constructor called" << std::endl;
	}
	*this = copy;
}

AForm&AForm::operator=(const AForm &)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AForm] assignment copy operator called" << std::endl;
	}
	//no copy because everything is contant at initialization
	return *this;
}

AForm::~AForm(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AForm] destructor called" << std::endl;
	}
}

AForm::AForm(const std::string &name, const size_t &requiredGradeToSign,
const size_t &requiredGradeToExecute, const std::string &target)
: target(target), _name(name), _requiredGradeToSign(requiredGradeToSign),
_requiredGradeToExecute(requiredGradeToExecute)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[AForm] name/required grade(to sign/to execute)/target constructor called" << std::endl;
	}
	
	if (_requiredGradeToSign < Bureaucrat::_highestPossibleGrade)
		throw GradeTooHighException();
	if (_requiredGradeToSign > Bureaucrat::_lowestPossibleGrade)
		throw GradeTooLowException();
	if (_requiredGradeToExecute < Bureaucrat::_highestPossibleGrade)
		throw GradeTooHighException();
	if (_requiredGradeToExecute > Bureaucrat::_lowestPossibleGrade)
		throw GradeTooLowException();
}

std::string AForm::getName(void) const
{
	return _name;
}

bool AForm::getIsSigned(void) const
{
	return _isSigned;
}

size_t AForm::getRequiredGradeToExecute(void) const
{
	return _requiredGradeToExecute;
}

size_t AForm::getRequiredGradeToSign(void) const
{
	return _requiredGradeToSign;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _requiredGradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const std::string &AForm::getTarget() const
{
	return target;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormIsUnsignedException();
	if (executor.getGrade() > getRequiredGradeToExecute())
		throw GradeTooLowToExecuteException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	std::string	text;
	if (form.getIsSigned())
		text = " is signed";
	else
		text = " is not signed";

	os << form.getName() << text << std::endl;
	os << "Required grade to sign: " << form.getRequiredGradeToSign() << std::endl;
	os << "Required grade to execute: " << form.getRequiredGradeToExecute() << std::endl << std::endl;
	return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char *AForm::FormIsUnsignedException::what() const throw()
{
	return "form is not signed";
}

const char *AForm::GradeTooLowToExecuteException::what() const throw()
{
	return "grade is too low to execute";
}

