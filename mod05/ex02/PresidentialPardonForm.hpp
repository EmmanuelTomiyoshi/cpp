#ifndef EX02_PRESIDENTIAL_PARDON_FORM_HPP
#define EX02_PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

#define PRES_PARDON_FORM_SIGN 25
#define PRES_PARDON_FORM_EXECUTE 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm&operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(const std::string &target);

		virtual void	execute(Bureaucrat const &executor) const;
};

#endif // EX02_PRESIDENTIAL_PARDON_FORM_HPP