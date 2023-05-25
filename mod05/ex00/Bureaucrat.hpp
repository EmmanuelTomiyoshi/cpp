#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
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
		Bureaucrat(const std::string &name, const unsigned short grade);
		
		std::string		getName(void) const;
		unsigned short	getGrade(void) const;
		void			setGrade(const unsigned short grade);

		void	incrementGrade(Bureaucrat &b);
		void	decrementGrade(Bureaucrat &b);

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

	private:
		const std::string	_name;
		unsigned short		_grade;

		static const unsigned short _highestPossibleGrade;
		static const unsigned short _lowestPossibleGrade;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // EX00_BUREAUCRAT_HPP