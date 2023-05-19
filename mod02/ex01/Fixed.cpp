#include "Fixed.hpp"

const int Fixed::_numFractionalBits = 8;

Fixed::Fixed( void ) : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _fixedPoint(integer << _numFractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

//1 << 8 = 2^8, which is 256 or 00000001 00000000
//this is binary multiplication!
Fixed::Fixed(const float f) : _fixedPoint(roundf(f * (1 << _numFractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&Fixed::operator=(const Fixed &t)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		this->setRawBits(t.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

//converting it back
float Fixed::toFloat ( void ) const
{
	return ((float) this->_fixedPoint / (1 << _numFractionalBits));
}

int Fixed::toInt( void ) const
{
	return this->_fixedPoint >> _numFractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}