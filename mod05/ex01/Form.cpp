#include "Form.hpp"
#include "Bureaucrat.hpp"

const size_t Form::_formatNameWidth = 20;
const size_t Form::_formatSignedWidth = 10;

Form::Form(void) :
_name("Standard form"), _isSigned(false),
_requiredGradeToExecute(Bureaucrat::_lowestPossibleGrade),
_requiredGradeToSign(Bureaucrat::_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] default constructor called" << std::endl;
	}
}

Form::Form(const Form &copy) :
_name("Standard form"), _isSigned(false),
_requiredGradeToExecute(Bureaucrat::_lowestPossibleGrade),
_requiredGradeToSign(Bureaucrat::_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] copy constructor called" << std::endl;
	}
	*this = copy;
}

Form&Form::operator=(const Form &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Form] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		_isSigned = copy._isSigned;
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

Form::Form(const std::string &name, const size_t &gradeToSign, const size_t &gradeToExecute)
: _name(name), _isSigned(false), _requiredGradeToExecute(gradeToExecute), _requiredGradeToSign(gradeToSign)
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

size_t Form::getRequiredGradeToExecute(void) const
{
	return _requiredGradeToExecute;
}

size_t Form::getRequiredGradeToSign(void) const
{
	return _requiredGradeToSign;
}

void Form::formatTable(void)
{
	std::cout << std::setfill(' ');
	std::cout << std::left << std::setw(_formatNameWidth) << _name;
	std::cout << " | ";
	std::cout << std::right << std::setw(_formatSignedWidth);
	
	if (this->_isSigned)
		std::cout << "yes";
	else
		std::cout << "no";

	std::cout << std::endl;
}

void Form::formatTableHeader(void)
{
	std::cout << std::left << std::setw(_formatNameWidth) << "Name";
	std::cout << " | ";
	std::cout << std::right << std::setw(_formatSignedWidth) << "Signed" << std::endl;

	std::cout << std::setfill('-') << std::setw(_formatNameWidth) << "";
	std::cout << " + ";
	std::cout << std::setw(_formatSignedWidth) << "" << std::endl;

	std::cout << std::setfill(' ');
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _requiredGradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}