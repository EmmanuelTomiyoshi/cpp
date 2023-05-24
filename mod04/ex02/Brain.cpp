#include "Brain.hpp"

Brain::Brain(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHMAGENTA << "[Brain]" << COLOR_RESET
		<< " default constructor called" << std::endl;
	}
}

Brain::Brain(const Brain &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHMAGENTA << "[Brain]" << COLOR_RESET
		<< " copy constructor called" << std::endl;
	}
	*this = copy;
}

Brain&Brain::operator=(const Brain &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHMAGENTA << "[Brain]" << COLOR_RESET
		<< " copy assignment operator called" << std::endl;
	}

	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << COLOR_BHMAGENTA << "[Brain]" << COLOR_RESET
		<< " default destructor called" << std::endl;
	}
}

void Brain::setIdea(const int &id, const std::string &idea)
{
	if (id < 0 || id >= 100)
		return ;
	ideas[id] = idea;
}

const std::string &Brain::getIdea(const int &id) const
{
	if (id < 0 || id >= 100)
		return ideas[0];
	return ideas[id];
}
