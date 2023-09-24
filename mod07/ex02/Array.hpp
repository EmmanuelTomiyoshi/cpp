#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#include <iostream>
#include <stdexcept>

#define SHOW_DEFAULT_MESSAGES 1

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &copy);
		Array&operator=(const Array &copy);
		~Array(void);

		//created two operator[] overloads because of a usability matter
		T &operator[](unsigned int index);				//can modify
		const T &operator[](unsigned int index) const;	//is constant

		const unsigned int &size(void) const;

	private:
		T				*_data;
		unsigned int	_size;
};

template <typename T>
Array<T>::Array() : _data(0), _size(0)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Array] default constructor called" << std::endl;
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Array] constructor with size \'n\' called" << std::endl;
	}
	for (unsigned int i = 0; i < _size; ++i)
	{
		_data[i] = T(); //default initializing
	}
}

template <typename T>
Array<T>::Array(const Array &copy) : _data(0), _size(0)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Array] copy constructor called" << std::endl;
	}
	*this = copy;
}

template <typename T>
Array<T>&Array<T>::operator=(const Array &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Array] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{
		delete[] _data;
		_data = 0;
		_size = copy._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = copy._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[Array] default destructor called" << std::endl;
	}
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < _size)
		return _data[index];
	else
		throw std::out_of_range("Index out of range");
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index < _size)
		return _data[index];
	else
		throw std::out_of_range("Index out of range");
}

template <typename T>
const unsigned int &Array<T>::size(void) const
{
	return _size;
}

template <typename T>
void displayElements(Array<T> &array, std::string type)
{
	std::cout << type << std::endl;
	std::cout << "size: " << array.size() << std::endl;
	for (unsigned int i = 0; i < array.size(); ++i)
		std::cout << array[i] << std::endl;
	std::cout << "----------------" << std::endl;
}

#endif // EX02_ARRAY_HPP