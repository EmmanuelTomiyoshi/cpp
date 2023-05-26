#ifndef EX01_BUREAUCRAT_HPP
#define EX01_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "colors.hpp"
#include "Form.hpp"

#define SHOW_DEFAULT_MESSAGES 1

class Bureaucrat {

	
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat&operator=(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat(const std::string &name);
		Bureaucrat(const std::string &name, const unsigned short grade);
		
		std::string		getName(void) const;
		unsigned short	getGrade(void) const;
		void			setGrade(const unsigned short grade);

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form &form);

		std::ostream&operator<<(std::ostream &os);

		//exceptions
		void checkGrade(const unsigned short grade); //where the exceptions are verified

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		static const unsigned short _highestPossibleGrade;
		static const unsigned short _lowestPossibleGrade;

	private:
		const std::string	_name;
		unsigned short		_grade;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // EX01_BUREAUCRAT_HPP