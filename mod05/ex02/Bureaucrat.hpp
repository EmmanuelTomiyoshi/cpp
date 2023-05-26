#ifndef EX01_BUREAUCRAT_HPP
#define EX01_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <iomanip>
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
		Bureaucrat(const std::string &name, const size_t grade);
		
		std::string		getName(void) const;
		size_t			getGrade(void) const;
		bool			getIsSigned(void) const;
		void			setGrade(const size_t grade);

		void			incrementGrade(void);
		void			decrementGrade(void);

		void			formatTable(void);
		void			formatTableHeader(void);

		void			signForm(Form &form);

		std::ostream&operator<<(std::ostream &os);

		//exceptions
		void 			checkGrade(const size_t grade);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual ~GradeTooHighException() throw() {}
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
		static const size_t _formatSignedWidth;

	private:
		const std::string	_name;
		size_t				_grade;
		bool				_isSigned;	//this works for only one form. If the
										//bureaucrat signs more than one
										//the value will be always true for this
										//implementation
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // EX01_BUREAUCRAT_HPP