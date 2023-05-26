#include "Bureaucrat.hpp"

const size_t Bureaucrat::_highestPossibleGrade = 1;
const size_t Bureaucrat::_lowestPossibleGrade = 150;
const size_t Bureaucrat::_formatNameWidth = 20;
const size_t Bureaucrat::_formatGradeWidth = 10;

Bureaucrat::Bureaucrat(void) : _name("bureaucrat"), _grade(_lowestPossibleGrade)
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

Bureaucrat::Bureaucrat(const std::string &name, const size_t grade) : _name(name)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Bureaucrat] name/grade constructor called" << std::endl;
	}
	setGrade(grade);
}

std::string Bureaucrat::getName(void) const
{
	return _name;
}

size_t Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::setGrade(const size_t grade)
{
	checkGrade(grade);
	_grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	setGrade(_grade + 1);
}

void Bureaucrat::formatTable(void)
{
	std::cout << std::setfill(' ');
	std::cout << std::left << std::setw(_formatNameWidth) << _name;
	std::cout << " | ";
	std::cout << std::right << std::setw(_formatGradeWidth) << _grade << std::endl;
}

void Bureaucrat::formatTableHeader(void)
{
	std::cout << std::left << std::setw(_formatNameWidth) << "Name";
	std::cout << " | ";
	std::cout << std::right << std::setw(_formatGradeWidth) << "Grade" << std::endl;

	std::cout << std::setfill('-') << std::setw(_formatNameWidth) << "";
	std::cout << " + ";
	std::cout << std::setw(_formatGradeWidth) << "" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat)
{
	os << Bureaucrat.getName() << ", bureaucrat grade is " << Bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::checkGrade(const size_t grade)
{
	if (grade < _highestPossibleGrade)
		throw GradeTooHighException(*this);
	if (grade > _lowestPossibleGrade)
		throw GradeTooLowException(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return errorMessage.c_str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return errorMessage.c_str();
}