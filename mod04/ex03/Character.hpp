#ifndef EX03_CHARACTER_HPP
#define EX03_CHARACTER_HPP

#include "AMateria.hpp"

class Character
{
	public:
		Character(void);
		Character(const Character &copy);
		Character&operator=(const Character &copy);
		~Character(void);

		virtual std::string const &getName(void) const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria 	*_slots[4];

};

#endif // EX03_CHARACTER_HPP