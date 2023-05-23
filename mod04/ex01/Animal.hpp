#ifndef EX01_ANIMAL_HPP
#define EX01_ANIMAL_HPP

#include <iostream>
#include <fstream>
#include "colors.hpp"

#define SHOW_DEFAULT_MESSAGES 0

class Animal {
	
	public:
		Animal(void);
		Animal(const Animal &copy);
		Animal&operator=(const Animal &copy);
		virtual ~Animal(void);

		virtual void makeSound(void) const;

		std::string getType(void) const;
		std::string getName(void) const;
		void setType(const std::string &type);
		void setName(const std::string &name);

		std::ostream&operator<<(std::ostream &os);

	protected:
		std::string type;
		std::string name;
};

std::ostream &operator<<(std::ostream& os, const Animal& animal);
void formatAnimalSound(const Animal *animal);
void formatAnimalCharacter(const Animal *animal);
std::string *readAnimalNames(const std::string &filename, const unsigned int count);

#endif // EX01_ANIMAL_HPP