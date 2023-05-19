#include "Fixed.hpp"

const int Fixed::_numFractionalBits = 8;

//default constructor
Fixed::Fixed( void ) : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
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
Fixed&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setRawBits(copy.getRawBits());
	return *this;
}

//destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//getters and setters
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}
