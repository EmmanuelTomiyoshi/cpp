#include "Span.hpp"

const int Span::_minShortestSpan = 5;

Span::Span(void) : _maxCapacity(0)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Span] add size constructor called" << std::endl;
	}
}

Span::Span(const Span &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Span] copy constructor called" << std::endl;
	}
	*this = copy;
}

Span&Span::operator=(const Span &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Span] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		
	}
	return *this;
}

Span::~Span(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Span] destructor called" << std::endl;
	}
}

Span::Span(unsigned int N) : _maxCapacity(N)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Span] default constructor called" << std::endl;
	}
}

void Span::addNumber(int number)
{
	if (_container.size() < _maxCapacity)
	{
		_container.push_back(number);
	}
	else
	{
		throw std::runtime_error("Vector capacity exceeded!");
	}
}

int Span::shortestSpan(void)
{
	if (_container.size() < 2)
		throw std::invalid_argument("The container must contain at least 2 elements to calculate the shortest span.");

	std::sort(_container.begin(), _container.end());

	int shortestSpan = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = _container.begin() + 1; it != _container.end(); ++it)
	{
		int span = *it - *(it - 1);
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return shortestSpan;
}

int Span::longestSpan(void)
{
	if (_container.size() < 2)
		throw std::invalid_argument("The container must contain at least 2 elements to calculate the longest span.");
	std::sort(_container.begin(), _container.end());

	return _container.back() - _container.front();
}

void Span::randomFill(void)
{
	std::srand(static_cast<unsigned int>(time(0)));

	while(_container.size() < _maxCapacity)
	{
		int randomNumber = std::rand() % 800000 + 1;
		if (isValidNumber(randomNumber))
			_container.push_back(randomNumber);
	}
}

const std::vector<int>&Span::getContainer(void) const
{
	return _container;
}

bool Span::isValidNumber(int number)
{
	if (_container.empty())
		return true;

	int minSpan = std::numeric_limits<int>::max();

	for (size_t i = 0; i < _container.size(); ++i)
	{
		int span = std::abs(number - _container[i]);
		if (span < minSpan)
		{
			minSpan = span;
		}
	}
	return minSpan >= _minShortestSpan; //ensure the shortest span has a minimum distance of five;
}