#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits>

#define SHOW_DEFAULT_MESSAGES 0

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

		bool	isValidNumber(int number);

		const std::vector<int>&getContainer(void) const;

		template <typename Iterator>
		void	addAllNumbersOnce(Iterator begin, Iterator end)
		{
			std::copy(begin, end, std::back_inserter(_container));
		}

	private:
		std::vector<int>	_container;
		unsigned int		_maxCapacity;
		static const int	_minShortestSpan;

};

#endif // EX01_SPAN_HPP