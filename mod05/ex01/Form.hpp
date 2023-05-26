#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {

	public:
		Form(void);
		Form(const Form &copy);
		Form&operator=(const Form &);
		~Form(void);

		Form(const std::string &name);
		Form(const std::string &name, const unsigned &gradeToExecute, const unsigned &gradeToSign);
		
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		size_t	getRequiredGradeToSign(void) const;
		size_t	getRequiredGradeToExecute(void) const;

		void			beSigned(const Bureaucrat &b);

		std::ostream&operator<<(std::ostream &os);

		//exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		const std::string			_name;
		bool						_isSigned;
		const size_t		_requiredGradeToExecute;
		const size_t		_requiredGradeToSign;
};

std::ostream &operator<<(std::ostream& os, const Form& bureaucrat);

#endif // EX01_FORM_HPP