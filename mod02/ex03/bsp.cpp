#include "Point.hpp"

bool on_vertex_or_edge(Point const a, Point const b, Point const c, Point const p)
{
	Fixed t(0);				//temp object just for min and max comparisons
	Fixed Ax(a.getXValue());
	Fixed Ay(a.getYValue());
	Fixed Bx(b.getXValue());
	Fixed By(b.getYValue());
	Fixed Cx(c.getXValue());
	Fixed Cy(c.getYValue());
	Fixed Px(p.getXValue());
	Fixed Py(p.getYValue());

	//check if point lies on a vertex
	if ((Px == Ax && Py == Ay) || (Px == Bx && Py == By) || (Px == Cx && Py == Cy))
		return false;
	
	//check if point lies on an edge
	if ((Px <= t.max(Ax, Bx) && Px >= t.min(Ax, Bx) && Py <= t.max(Ay, By) && Py >= t.min(Ay, By))
	|| (Px <= t.max(Bx, Cx) && Px >= t.min(Bx, Cx) && Py <= t.max(By, Cy) && Py >= t.min(By, Cy))
	|| (Px <= t.max(Ax, Cx) && Px >= t.min(Ax, Cx) && Py <= t.max(Ay, Cy) && Py >= t.min(Ay, Cy)))
	{
		return false;
	}
	return true;
}

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area;
	Fixed	x1(a.getXValue());
	Fixed	y1(a.getYValue());
	Fixed	x2(b.getXValue());
	Fixed	y2(b.getYValue());
	Fixed	x3(c.getXValue());
	Fixed	y3(c.getYValue());

	area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2);
	area = area.max(area, Fixed(area * -1)); //get absolute value, because math could lead to negative
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int 	areaTriangle;
	int 	areaPoint;
	
	areaTriangle = area(a, b, c).toInt();

	areaPoint = area(point, b, c).toInt();
	areaPoint += area(a, point, c).toInt();
	areaPoint += area(a, b, point).toInt();

	std::cout << "Triangle area:\t" << areaTriangle << std::endl;
	std::cout << "Point area:\t" << areaPoint << std::endl << std::endl;

	if (on_vertex_or_edge(a, b, c, point) && areaTriangle == areaPoint)
		return true;
	return false;
}
