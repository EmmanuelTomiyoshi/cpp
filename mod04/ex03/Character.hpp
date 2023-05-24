#ifndef EX03_CHARACTER_HPP
#define EX03_CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SLOTS 4

class Character : public ICharacter
{
	public:
		Character(void);
		Character(const Character &copy);
		Character&operator=(const Character &copy);
		~Character(void);

		Character(const std::string &name);

		virtual std::string const &getName(void) const;
		virtual void setName(const std::string &name);
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

		const AMateria *getMateria(int idx) const;

	private:
		std::string	_name;
		AMateria 	*_inventory[SLOTS];
		AMateria	*_deactivatedMateria;

};

#endif // EX03_CHARACTER_HPP