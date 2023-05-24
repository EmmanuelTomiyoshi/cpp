#ifndef EX03_AMATERIA_HPP
#define EX03_AMATERIA_HPP

#include <iostream>
#include "colors.hpp"
#include "ICharacter.hpp"

#define SHOW_DEFAULT_MESSAGES 0

class AMateria
{
	public:
		AMateria(void);
		AMateria(const AMateria &copy);
		AMateria&operator=(const AMateria &copy);
		virtual ~AMateria(void);

		AMateria(std::string const &type);

		std::string const &getType(void) const; //Returns the materia type
		void setType(const std::string &type);

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;

		std::ostream&operator<<(std::ostream &os);

	protected:
		std::string	_type;

};

std::ostream &operator<<(std::ostream& os, const AMateria& animal);

#endif // EX02_ANIMAL_HPP