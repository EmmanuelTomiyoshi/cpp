#ifndef EX02_SHRUBBERY_CREATION_FORM_HPP
#define EX02_SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

#define SHRUBBERY_CREATION_FORM_SIGN 145
#define SHRUBBERY_CREATION_FORM_EXECUTE 137

#define ASCII_TREE \
"              * *\
           *    *  *\
      *  *    *     *  *\
     *     *    *  *    *\
 * *   *    *    *    *   *\
 *     *  *    * * .#  *   *\
 *   *     * #.  .# *   *\
  *     \"#.  #: #\" * *    *\
 *   * * \"#. ##\"       *\
   *       \"###\
             \"##\
              ##.\
              .##:\
              :###\
              ;###\
            ,####.\
/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\""

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm&operator=(const ShrubberyCreationForm &);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(const std::string &target);

		virtual void	execute(Bureaucrat const &executor) const;

	private:
};

#endif // EX02_SHRUBBERY_CREATION_FORM_HPP