#ifndef EX03_POINT_HPP
#define EX03_POINT_HPP

#include "Fixed.hpp"

#define COLOR_RESET  	"\x1b[0m"
#define COLOR_RED   	"\x1b[31m"
#define COLOR_GREEN 	"\x1b[32m"
#define COLOR_BLUE    	"\x1b[34m"
#define PADDING 		2

class Point {
	
	public:

		Point(void);
		Point(const float x, const float y);
		Point(const Point &copy);
		Point&operator=(const Point &copy);
		~Point(void);

		const Fixed &getXValue(void) const;
		const Fixed &getYValue(void) const;


	private:
		Fixed const _x;
		Fixed const _y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);
void draw_triangle(Point const a, Point const b, Point const c, Point const p);

#endif // EX03_POINT_HPP
