#ifndef EX02_BUREAUCRAT_HPP
#define EX02_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>
#include "colors.hpp"
#include "AForm.hpp"

#define SHOW_DEFAULT_MESSAGES 0

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

		void 			checkGrade(const size_t grade);
		void			incrementGrade(void);
		void			decrementGrade(void);

		void			formatTable(void);
		void			formatTableHeader(void);

		void			signForm(AForm &form);
		void			executeForm(AForm const &form);

		std::ostream&operator<<(std::ostream &os);

		//exceptions
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

		void	executeForm(AForm const &form) const;

		static const size_t _highestPossibleGrade;
		static const size_t _lowestPossibleGrade;
		static const size_t	_formatNameWidth;
		static const size_t	_formatGradeWidth;
		static const size_t _formatSignedWidth;

	private:
		void				setGrade(const size_t grade);
		const std::string	_name;
		size_t				_grade;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // EX02_BUREAUCRAT_HPP