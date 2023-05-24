#ifndef EX02_BRAIN_HPP
#define EX02_BRAIN_HPP

#include <iostream>
#include "colors.hpp"
#include "AAnimal.hpp"

class Brain {
	
	public:
		Brain(void);
		Brain(const Brain &copy);
		Brain&operator=(const Brain &copy);
		~Brain(void);

		void 				setIdea(const int &id, const std::string &idea);
		const std::string	&getIdea(const int &id) const;

	private:
		std::string ideas[100];
};


#endif // EX02_BRAIN_HPP