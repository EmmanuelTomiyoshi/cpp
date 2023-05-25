#include "Bureaucrat.hpp"

const unsigned short Bureaucrat::_highestPossibleGrade = 1;
const unsigned short Bureaucrat::_lowestPossibleGrade = 150;

Bureaucrat::Bureaucrat(void)  : _name("bureaucrat"), _grade(_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Bureaucrat] default constructor called" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name("bureaucrat"), _grade(_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Bureaucrat] copy constructor called" << std::endl;
	}
	*this = copy;
}

Bureaucrat&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Bureaucrat] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Bureaucrat] destructor called" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(_lowestPossibleGrade)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Bureaucrat] name constructor called" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned short grade) : _name(name)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Bureaucrat] name/grade constructor called" << std::endl;
	}

	checkGrade(grade);
	
	_grade = grade; //if all went well, the grade is then assigned
}

std::string Bureaucrat::getName(void) const
{
	return _name;
}

unsigned short Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::setGrade(const unsigned short grade)
{
	checkGrade(grade);
	_grade = grade;
}

void Bureaucrat::incrementGrade(Bureaucrat &b)
{
	setGrade(b._grade--);
}

void Bureaucrat::decrementGrade(Bureaucrat &b)
{
	setGrade(b._grade++);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat)
{
	os << Bureaucrat.getName() << ", bureaucrat grade is " << Bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::checkGrade(const unsigned short grade)
{
	if (grade < _highestPossibleGrade)
		throw GradeTooHighException();
	if (grade > _lowestPossibleGrade)
		throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: exception: Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: exception: Grade is too low";
}