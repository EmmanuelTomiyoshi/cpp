#ifndef EX03_ICE_HPP
#define EX03_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &copy);
		Ice&operator=(const Ice &copy);
		~Ice(void);

		virtual AMateria *clone(void) const;
		virtual void use(ICharacter &target);

	private:

};

#endif // EX03_ICE_HPP