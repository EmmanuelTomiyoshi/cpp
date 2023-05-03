#include "Fixed.hpp"

const int Fixed::_numFractionalBits = 8;

//default constructor
Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

//copy constructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	/*or this
	this->_fixedPoint = copy._fixedPoint;*/
}

//copy assignment operator overload
Fixed&Fixed::operator=(const Fixed &t)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		this->setRawBits(t.getRawBits());
	return *this;
}

//destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}