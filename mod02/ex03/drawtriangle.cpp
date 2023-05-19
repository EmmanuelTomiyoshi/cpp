#include "Point.hpp"

Point check_highest_value(Point const a, Point const b, Point const c, Point const p)
{
	Fixed 	t;
	Fixed 	Ax(a.getXValue());
	Fixed 	Ay(a.getYValue());
	Fixed 	Bx(b.getXValue());
	Fixed 	By(b.getYValue());
	Fixed 	Cx(c.getXValue());
	Fixed 	Cy(c.getYValue());
	Fixed 	Px(p.getXValue());
	Fixed 	Py(p.getYValue());

	const float x = t.max(t.max(Ay, By), t.max(Ay, Cy)).toInt();
	const float y = t.max(t.max(Ax, Bx), t.max(Ax, Cx)).toInt();

	Point	high(x + PADDING, y + PADDING);

	return (high);

}

void draw_triangle(Point const a, Point const b, Point const c, Point const p)
{
	bool	overlap; //whether point overlaps a vertex

	// Get the coordinates of the triangle vertices
	Fixed	t;
	Fixed 	Ax(a.getXValue());
	Fixed 	Ay(a.getYValue());
	Fixed 	Bx(b.getXValue());
	Fixed 	By(b.getYValue());
	Fixed 	Cx(c.getXValue());
	Fixed 	Cy(c.getYValue());
	Fixed 	Px(p.getXValue());
	Fixed 	Py(p.getYValue());

	//check if point lies on a vertex
	if ((Px == Ax && Py == Ay) || (Px == Bx && Py == By) || (Px == Cx && Py == Cy))
		overlap = true;
	
	//check if point lies on an edge
	if ((Px <= t.max(Ax, Bx) && Px >= t.min(Ax, Bx) && Py <= t.max(Ay, By) && Py >= t.min(Ay, By))
	|| (Px <= t.max(Bx, Cx) && Px >= t.min(Bx, Cx) && Py <= t.max(By, Cy) && Py >= t.min(By, Cy))
	|| (Px <= t.max(Ax, Cx) && Px >= t.min(Ax, Cx) && Py <= t.max(Ay, Cy) && Py >= t.min(Ay, Cy)))
	{
		overlap = true;
	}

	// Create and define the size of the matrix with the highest value
	Point	size = check_highest_value(a, b, c, p);
	int		matx = size.getXValue().toInt();
	int		maty = size.getYValue().toInt();

	char matrix[matx][maty];

    // Draw the lines of the triangle
    for (int i = 0; i < matx; i++)
	{
        for (int j = 0; j < maty; j++)
		{
            if (i == Py.toInt() && j == Px.toInt())
                matrix[i][j] = 'P';
            else if (i == Ay.toInt() && j == Ax.toInt())
                matrix[i][j] = 'A';
            else if (i == By.toInt() && j == Bx.toInt())
                matrix[i][j] = 'B';
            else if (i == Cy.toInt() && j == Cx.toInt())
                matrix[i][j] = 'C';
            else if (((Bx - Ax) * (i - Ay.toInt()) - (By - Ay) * (j - Ax.toInt())) >= 0 &&
                     ((Cx - Bx) * (i - By.toInt()) - (Cy - By) * (j - Bx.toInt())) >= 0 &&
                     ((Ax - Cx) * (i - Cy.toInt()) - (Ay - Cy) * (j - Cx.toInt())) >= 0)
            	matrix[i][j] = '*';
			else
			 	matrix[i][j] = ' ';
        }
    }

	// Draw the matrix
    for (int i = 0; i < matx; i++)
	{
        for (int j = 0; j < maty; j++)
		{
            if (matrix[i][j] == '*')
                std::cout << COLOR_RESET << "*";
			else if (matrix[i][j] == 'P')
			{
				if (overlap == true)
					std::cout << COLOR_RED << matrix[i][j];
				else
					std::cout << COLOR_GREEN << matrix[i][j];
			}
            else
                std::cout << COLOR_BLUE << matrix[i][j];
        }
        std::cout << std::endl;
    }
	std::cout << COLOR_RESET;
}
