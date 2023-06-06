#ifndef EX03_INTERN_HPP
#define EX03_INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Bureaucrat;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern&operator=(const Intern &copy);
		~Intern(void);

		AForm *makeForm(std::string nameForm, std::string targetForm) const;

		class FormDoesNotExist : public std::exception
		{
			const char *what() const throw();
		};

	private:
		static AForm *_newPresidentialPardonForm(const std::string &target);
		static AForm *_newRobotomyRequestForm(const std::string &target);
		static AForm *_newShrubberyCreationForm(const std::string &target);
};

#endif // EX03_INTERN_HPP