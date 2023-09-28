#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits>

#define SHOW_DEFAULT_MESSAGES 0

// This class will have a member function called addNumber() to add a single number
// to the Span. It will be used in order to fill it. Any attempt to add a new element if there
// are already N elements stored should throw an exception.

class Span
{
	public:
		Span(void);
		~Span();
		Span(const Span &copy);
		Span&operator=(const Span &copy);

		Span(unsigned int N);

		void	addNumber(int number);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	randomFill(void);

		const std::vector<int>&getContainer(void) const;

		template <typename Iterator>
		void	addAllNumbersOnce(Iterator begin, Iterator end)
		{
			std::copy(begin, end, std::back_inserter(_container));
		}

	private:
		std::vector<int>	_container;
		unsigned int		_maxCapacity;

};

#endif // EX00_EASYFIND_HPP