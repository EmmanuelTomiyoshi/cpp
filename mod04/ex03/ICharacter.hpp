#ifndef EX03_ICHARACTER_HPP
#define EX03_ICHARACTER_HPP

#include <iostream>

class AMateria; //prototype

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const &getName(void) const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;

	private:

};

#endif // EX03_ICHARACTER_HPP