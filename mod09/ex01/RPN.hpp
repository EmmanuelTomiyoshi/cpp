#ifndef EX01_RPN_HPP
#define EX01_RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>

#define SHOW_DEFAULT_MESSAGES	0

class RPN
{
	public:
		RPN(void);
		~RPN();
		RPN(const RPN &copy);
		RPN&operator=(const RPN &copy);

		void	evaluate(std::string expression);
		int		getResult(void) const;

	private:
		std::stack<int> _stack;
		int _result;
		int operate(int operand, int &a, int &b) const;

};

//reference: https://isaaccomputerscience.org/concepts/dsa_toc_rpn?examBoard=all&stage=all

#endif // EX01_RPN_HPP