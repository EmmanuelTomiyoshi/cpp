#ifndef EX02_AFORM_HPP
#define EX02_AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {

	public:
		AForm(void);
		AForm(const AForm &copy);
		AForm&operator=(const AForm &copy);
		virtual ~AForm(void);

		AForm(const std::string &name, const size_t &_requiredGradeToSign,
			const size_t &_requiredGradeToExecute, const std::string &target);

		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		size_t				getRequiredGradeToSign(void) const;
		size_t				getRequiredGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &b);

		void				formatTable(void);
		void				formatTableHeader(void);

		const std::string	&getTarget(void) const;

		virtual void		execute(Bureaucrat const &executor) const = 0;
		void				canExecute(Bureaucrat const &executor) const;

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

		class FormIsUnsignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowToExecuteException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		static const size_t	_formatNameWidth;
		static const size_t	_formatSignedWidth;

	protected:
		std::string					target;

	private:
		const std::string			_name;
		bool						_isSigned;
		const size_t				_requiredGradeToSign;
		const size_t				_requiredGradeToExecute;
};

std::ostream &operator<<(std::ostream& os, const AForm& form);

#endif // EX02_AFORM_HPP