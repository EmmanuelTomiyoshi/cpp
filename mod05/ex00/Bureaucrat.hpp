#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>
#include "colors.hpp"

#define SHOW_DEFAULT_MESSAGES 1

class Bureaucrat {

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat&operator=(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat(const std::string &name);
		Bureaucrat(const std::string &name, const size_t grade);
		
		std::string			getName(void) const;
		size_t				getGrade(void) const;
		void				setGrade(const size_t grade);

		void				incrementGrade(void);
		void				decrementGrade(void);

		//this whole prints functions could be a separated class, that inherits
		//from Bureaucrat. It would be the best practice, but for now let's
		//stick with this manner
		void				formatTable(void);
		void				formatTableHeader(void);

		std::ostream&operator<<(std::ostream &os);

		//exceptions
		void 				checkGrade(const size_t grade); //where the exceptions are verified

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

		static const size_t _highestPossibleGrade;
		static const size_t _lowestPossibleGrade;
		static const size_t	_formatNameWidth;
		static const size_t	_formatGradeWidth;

	private:
		const std::string	_name;
		size_t				_grade;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // EX00_BUREAUCRAT_HPP