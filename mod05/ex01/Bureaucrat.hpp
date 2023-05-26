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

		void			incrementGrade(void);
		void			decrementGrade(void);

		void			signForm(Form &form);

		std::ostream&operator<<(std::ostream &os);

		//exceptions
		void 			checkGrade(const unsigned short grade); //where the exceptions are verified

		class GradeTooHighException: public std::exception
		{
			public:
				virtual ~GradeTooHighException() throw() {} //it's a best practice to include a destructor in the
															//derived class with the same exception specification of
															//the super class (in this case, std::exception)
				GradeTooHighException(const Bureaucrat &b) : bureaucrat(b)
				{
					errorMessage = "Error: exception: " + bureaucrat.getName() + "\'s grade is too high";
				}
				virtual const char *what() const throw();
			private:
				const Bureaucrat&	bureaucrat;
				std::string			errorMessage;
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual ~GradeTooLowException() throw() {}
				GradeTooLowException(const Bureaucrat &b) : bureaucrat(b)
				{
					errorMessage = "Error: exception: " + bureaucrat.getName() + "\'s grade is too low";
				}
				virtual const char *what() const throw();
			private:
				const Bureaucrat&	bureaucrat;
				std::string			errorMessage;
		};

		static const unsigned short _highestPossibleGrade;
		static const unsigned short _lowestPossibleGrade;

	private:
		const std::string	_name;
		unsigned short		_grade;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // EX01_BUREAUCRAT_HPP