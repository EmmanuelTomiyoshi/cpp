#include "Fixed.hpp"

const int Fixed::_numFractionalBits = 8;

Fixed::Fixed( void ) : _fixedPoint(0) { }

Fixed::Fixed(const int integer) : _fixedPoint(integer << _numFractionalBits) { }

Fixed::Fixed(const float f) : _fixedPoint(roundf(f * (1 << _numFractionalBits))) { }

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed&Fixed::operator=(const Fixed &t)
{
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

Fixed::~Fixed() { }


//increment and decrement
Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;

	this->setRawBits(this->getRawBits() + 1); //creates a copy and then return,
											  //but before add 1 to itself
	return (copy);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (copy);
}

//comparison
bool Fixed::operator<(const Fixed &lt) const
{
	return (this->_fixedPoint < lt._fixedPoint);
}

bool Fixed::operator>(const Fixed &mt) const
{
	return (this->_fixedPoint > mt._fixedPoint);
}

bool Fixed::operator>=(const Fixed &met) const
{
	return (this->_fixedPoint >= met._fixedPoint);
}

bool Fixed::operator<=(const Fixed &let) const
{
	return (this->_fixedPoint <= let._fixedPoint);
}

bool Fixed::operator==(const Fixed &eq) const
{
	return (this->_fixedPoint == eq._fixedPoint);
}

bool Fixed::operator!=(const Fixed &diff) const
{
	return (this->_fixedPoint != diff._fixedPoint);
}


//arithmetic
Fixed Fixed::operator+(const Fixed &plus)
{
	if (plus._fixedPoint > INT_MAX || plus._fixedPoint < INT_MIN)
		return (Fixed(0));
	else if ((this->_fixedPoint + plus._fixedPoint) > INT_MAX
		||   (this->_fixedPoint + plus._fixedPoint) < INT_MIN)
		return (Fixed(0));
	return this->toFloat() + plus.toFloat();
}

Fixed Fixed::operator-(const Fixed &minus)
{
	if (minus._fixedPoint > INT_MAX || minus._fixedPoint < INT_MIN)
		return (Fixed(0));
	else if ((this->_fixedPoint - minus._fixedPoint) > INT_MAX
		||   (this->_fixedPoint - minus._fixedPoint) < INT_MIN)
		return (Fixed(0));
	return this->toFloat() - minus.toFloat();
}

Fixed Fixed::operator*(const Fixed &mult)
{
	if (mult._fixedPoint > INT_MAX || mult._fixedPoint < INT_MIN)
		return (Fixed(0));
	else if ((this->_fixedPoint * mult._fixedPoint) > INT_MAX
		||   (this->_fixedPoint * mult._fixedPoint) < INT_MIN)
		return (Fixed(0));
	
	return this->toFloat() * mult.toFloat();
}

Fixed Fixed::operator/(const Fixed &div)
{
	if (div._fixedPoint == 0)
	{
		std::cout << "Can't divide by zero.\n" << std::endl;
		return(Fixed(0));
	}
	if (div._fixedPoint > INT_MAX || div._fixedPoint < INT_MIN)
		return (Fixed(0));
	else if ((this->_fixedPoint / div._fixedPoint) > INT_MAX
		||   (this->_fixedPoint / div._fixedPoint) < INT_MIN)
		return (Fixed(0));
	return this->toFloat() / div.toFloat();
}


//min and max
Fixed &Fixed::min(Fixed &fp1, Fixed &fp2)
{
	if (fp1.getRawBits() < fp2.getRawBits())
		return fp1;
	return fp2;
}

const Fixed &Fixed::min(Fixed const &fp1, Fixed const &fp2)
{
	if (fp1.getRawBits() < fp2.getRawBits())
		return fp1;
	return fp2;
}

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2)
{
	if (fp1.getRawBits() > fp2.getRawBits())
		return fp1;
	return fp2;
}

const Fixed &Fixed::max(Fixed const &fp1, Fixed const &fp2)
{
	if (fp1.getRawBits() > fp2.getRawBits())
		return fp1;
	return fp2;
}
