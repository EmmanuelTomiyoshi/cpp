#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {

	public:
		Form(void);
		Form(const Form &copy);
		Form&operator=(const Form &copy);
		~Form(void);

		Form(const std::string &name);
		Form(const std::string &name, const size_t &gradeToExecute, const size_t &gradeToSign);
		
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		size_t			getRequiredGradeToSign(void) const;
		size_t			getRequiredGradeToExecute(void) const;
		
		void			formatTable(void);
		void			formatTableHeader(void);

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

		static const size_t	_formatNameWidth;
		static const size_t	_formatSignedWidth;

	private:
		const std::string			_name;
		bool						_isSigned;
		const size_t				_requiredGradeToExecute;
		const size_t				_requiredGradeToSign;
};

std::ostream &operator<<(std::ostream& os, const Form& form);

#endif // EX01_FORM_HPP