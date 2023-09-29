#include "Span.hpp"

bool hasDuplicates(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] == vec[j]) {
                return true; // Found a duplicate
            }
        }
    }
    return false; // No duplicates found
}

int main(void)
{
	Span sp = Span(10);
	Span spTarget = Span();

	sp.randomFill();
	spTarget.addAllNumbersOnce((sp.getContainer()).begin(), (sp.getContainer()).end());

	std::cout << "Are there duplicated values? " << std::endl;
	if (hasDuplicates(spTarget.getContainer()))
		std::cout << "Yes";
	else
	 	std::cout << "No";
	std::cout << std::endl;

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