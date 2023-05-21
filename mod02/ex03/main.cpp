#include "Point.hpp"

void check_bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
}

int main(void)
{
	Point a(1, 5);
	Point b(5, 1);
	Point c(9, 5);
	Point point(8, 5);

	std::cout << std::endl;

	check_bsp(a, b, c, point);

	//only use draw_triangle if the coordinates are positive integers
	draw_triangle(a, b, c, point);
	
	return (0);
}

//INSIDE

// Point a(1, 5);
// Point b(5, 1);
// Point c(9, 5);
// Point point(5, 4);

//OUTSIDE

// Point a(1, 5);
// Point b(5, 1);
// Point c(9, 5);
// Point point(10, 2);

