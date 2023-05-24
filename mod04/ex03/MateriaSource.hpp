#ifndef EX03_MATERIASOURCE_HPP
#define EX03_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SLOTS 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		MateriaSource&operator=(const MateriaSource &copy);
		~MateriaSource(void);

		virtual void learnMateria(AMateria *m);
		virtual AMateria* createMateria(std::string const &type);

		const AMateria *getMateria(int idx) const;

	private:
		AMateria *_inventory[SLOTS];
};

#endif // EX03_MATERIASOURCE_HPP