#include "MutantStack.hpp"

int main(void)
{
	//The problem: stack is not iterable
	{
		std::stack<int> stackOverflow;

		stackOverflow.push(std::numeric_limits<int>::max() - 3);
		stackOverflow.push(std::numeric_limits<int>::max() - 2);
		stackOverflow.push(std::numeric_limits<int>::max() - 1);

		std::cout << "STACK ELEMENTS: " << std::endl;
		while(!stackOverflow.empty())
		{
			int element = stackOverflow.top();
			stackOverflow.pop();

			std::cout << element << std::endl;
		}
	}

	//The solution: let's make it iterable!
	//There are two options one could think of, which is or implementing a
	//custom logic to access and process its elements, or using its underlying
	//containers, such as deque (double-ended queue)

	//1) Implementing a custom logic

	{
		std::stack<int> stackOverflow;
		std::vector<int> ahYeah;

		stackOverflow.push(std::numeric_limits<int>::max() - 3);
		stackOverflow.push(std::numeric_limits<int>::max() - 2);
		stackOverflow.push(std::numeric_limits<int>::max() - 1);

		//assigning the stack value
		std::cout << "VECTOR (underlying container) ELEMENTS: " << std::endl;
		while (!stackOverflow.empty())
		{
			ahYeah.push_back(stackOverflow.top());
			stackOverflow.pop();
		}

		//printing from vector (ahYeah)
		for (size_t i = 0; i < ahYeah.size(); ++i)
		{
			std::cout << ahYeah[i] << std::endl;
		}
	}
	std::cout << std::endl;

	//still, we are making a copy to another deck. There's certainly a better
	//way to do this. Then, let's use...

	//2)Underlying container

	{
		MutantStack<int> mutantStack;

		mutantStack.push(1);
		mutantStack.push(2);
		mutantStack.push(3);
	
		std::cout << "Using begin() and end() functions:" << std::endl;
		for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Using rbegin() and rend() functions:" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		mutantStack.pop();
		mutantStack.pop();
		mutantStack.pop();
		std::cout << std::endl;
	}

	{
		//3) Subject Tests
		MutantStack<int> mstack;

		std::cout << "Subject Tests" << std::endl;
		mstack.push(5);
		mstack.push(17);

		std::cout << "What\'s on top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		//if you uncomment this, you'll see the iterator changing
		//++it;
		while (it != ite)
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout << std::endl;
	}
}