#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);


	try
	{
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what() << std::endl;
	}
}