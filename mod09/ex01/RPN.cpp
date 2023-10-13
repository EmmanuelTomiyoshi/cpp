#include "RPN.hpp"

RPN::RPN(void) : _stack(), _result(0)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RPN] constructor called" << std::endl;
	}
}

RPN::RPN(const RPN &copy) : _stack(), _result(0)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RPN] copy constructor called" << std::endl;
	}
	*this = copy;
}

RPN&RPN::operator=(const RPN &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RPN] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		_stack = copy._stack;
		_result = copy._result;
	}
	return *this;
}

RPN::~RPN(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[RPN] destructor called" << std::endl;
	}
}

int RPN::operate(int operand, int &a, int &b) const
{
	if (operand == '+')
	{
		return a + b;
	}
	else if (operand == '-')
	{
		return a - b;
	}
	else if (operand == '*')
	{
		return a * b;
	}
	else if (operand == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error: Division by zero");
		return a / b;
	}
	return 0;
}

int RPN::getResult(void) const
{
	return _result;
}

void RPN::evaluate(std::string expression)
{
	if (expression.size() < 3)
		throw std::runtime_error("Error: the expression is incorrect.");

	std::string token;
	std::istringstream iss(expression);

	int firstValue, secondValue = 0;
	while (iss)
	{
		iss >> token;
		if (!iss)
			break ;
		if (token.size() != 1)
		{
			throw std::runtime_error("Error: the expression is incorrect.");
		}
		if (std::isdigit(token[0]))
		{
			_stack.push(atoi(token.c_str()));
		}
		if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			if (_stack.size() <= 1)
			{
				throw std::runtime_error("Error: the expression is incorrect.");
			}
			firstValue = _stack.top();
			_stack.pop();
			secondValue = _stack.top();
			_stack.pop();

			_result = operate(token[0], secondValue, firstValue);
			//the first item off the stack becomes the right operand and vice-versa
			_stack.push(_result);
		}
	}
}
