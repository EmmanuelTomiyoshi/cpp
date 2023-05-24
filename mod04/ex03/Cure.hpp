#ifndef EX03_CURE_HPP
#define EX03_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &copy);
		Cure&operator=(const Cure &copy);
		~Cure(void);

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);

	private:

};

#endif // EX03_CURE_HPP