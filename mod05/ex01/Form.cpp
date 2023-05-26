#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :
_name("document"), _isSigned(0),
_requiredGradeToExecute(Bureaucrat::_lowestPossibleGrade),
_requiredGradeToSign(Bureaucrat::_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] default constructor called" << std::endl;
	}
}

Form::Form(const Form &copy) :
_name("document"), _isSigned(0),
_requiredGradeToExecute(Bureaucrat::_lowestPossibleGrade),
_requiredGradeToSign(Bureaucrat::_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] copy constructor called" << std::endl;
	}
	*this = copy;
}

Form&Form::operator=(const Form &) //has no name because there isn't something to copy
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] assignment copy operator called" << std::endl;
	}
	return *this;
}

Form::~Form(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] destructor called" << std::endl;
	}
}

Form::Form(const std::string &name) :
_name(name),
_requiredGradeToExecute(Bureaucrat::_lowestPossibleGrade),
_requiredGradeToSign(Bureaucrat::_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] name constructor called" << std::endl;
	}
	_isSigned = 0;
}

Form::Form(const std::string &name, const unsigned &gradeToSign, const unsigned &gradeToExecute)
: _name(name), _requiredGradeToExecute(gradeToExecute), _requiredGradeToSign(gradeToSign)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] name/required grade(to sign/to execute) constructor called" << std::endl;
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

std::string Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

unsigned short Form::getRequiredGradeToExecute(void) const
{
	return _requiredGradeToExecute;
}

unsigned short Form::getRequiredGradeToSign(void) const
{
	return _requiredGradeToSign;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _requiredGradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
	std::string	text;
	if (Form.getIsSigned())
		text = " is signed.";
	else
		text = " is not signed.";

	os << "Form: " << Form.getName() << text << std::endl;
	os << "Required grade to sign: " << Form.getRequiredGradeToSign() << std::endl;
	os << "Required grade to execute: " << Form.getRequiredGradeToExecute() << std::endl;
	return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Error: exception: Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Error: exception: Grade is too low";
}