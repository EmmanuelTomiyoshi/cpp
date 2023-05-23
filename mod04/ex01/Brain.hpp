#ifndef EX01_BRAIN_HPP
#define EX01_BRAIN_HPP

#include <iostream>
#include "colors.hpp"
#include "Animal.hpp"

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


#endif // EX01_BRAIN_HPP