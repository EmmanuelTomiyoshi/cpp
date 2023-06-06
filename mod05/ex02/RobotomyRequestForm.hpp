#ifndef EX02_ROBOTOMY_REQUEST_FORM_HPP
#define EX02_ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <time.h>		//time()
#include <sys/time.h>	//struct timeval
#include <unistd.h>		//usleep()

#define ROBOTOMY_REQUEST_FORM_SIGN 72
#define ROBOTOMY_REQUEST_FORM_EXECUTE 45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm&operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const std::string &target);

		virtual void	execute(Bureaucrat const &executor) const;
};

#endif // EX02_ROBOTOMY_REQUEST_FORM_HPP