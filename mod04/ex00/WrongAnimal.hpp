#ifndef EX00_WRONGANIMAL_HPP
#define EX00_WRONGANIMAL_HPP

#include <iostream>
#include "colors.hpp"
#include "Animal.hpp"

class WrongAnimal {
	
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal&operator=(const WrongAnimal &copy);
		virtual ~WrongAnimal(void);

		void makeSound(void) const;

		std::string getType(void) const;
		std::string getName(void) const;
		void setType(const std::string &type);
		void setName(const std::string &name);

		std::ostream&operator<<(std::ostream &os);

	protected:
		std::string type;
		std::string name;
};

std::ostream &operator<<(std::ostream& os, const WrongAnimal& wrongAnimal);
void formatAnimalSound(const WrongAnimal *animal);

#endif // EX00_WRONGANIMAL_HPP