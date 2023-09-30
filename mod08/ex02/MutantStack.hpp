#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <deque>
#include <limits>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &copy);
		MutantStack&operator=(const MutantStack &copy);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type			_container;	//alias for each container iterator
		typedef typename _container::iterator					iterator;
		typedef typename _container::const_iterator				const_iterator;
		typedef typename _container::reverse_iterator			reverse_iterator;
		typedef typename _container::const_reverse_iterator		const_reverse_iterator;

		iterator				begin();			//declaring the iterator functions
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;

	private:

};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy)
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &copy)
{
	std::stack<T>::operator=(copy);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{

}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();	//"c" access the underlying container. In this case, deque
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T> typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T> typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}





#endif //EX02_MUTANTSTACK_HPP

