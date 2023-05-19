#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{

}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{

}

Point::Point(const Point &copy)
{
	*this = copy;
}

Point&Point::operator=(const Point &copy)
{
	if (this != &copy)
	{
		(Fixed &) this->_x = copy.getXValue();
		(Fixed &) this->_y = copy.getYValue();
	}
	return *this;
}

const Fixed &Point::getXValue(void) const
{
	return _x;
}

const Fixed &Point::getYValue(void) const
{
	return _y;
}

Point::~Point(void)
{

}