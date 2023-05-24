#ifndef EX02_AANIMAL_HPP
#define EX02_AANIMAL_HPP

#include <iostream>
#include <fstream>
#include "colors.hpp"

#define SHOW_DEFAULT_MESSAGES 0
#define MAX_SIZE_ANIMAL_OBJECTS 50

class Animal {
	
	public:
		Animal(void);
		Animal(const Animal &copy);
		Animal&operator=(const Animal &copy);
		virtual ~Animal(void);

		virtual void makeSound(void) const = 0;

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
void update_progress_bar(const int progress, const std::string &animal);

#endif // EX02_AANIMAL_HPP