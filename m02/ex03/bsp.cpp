#include "Point.hpp"

float area(Point one, Point two, Point three)
{
	return (std::abs(one.getAtr(0) * (two.getAtr(1) - three.getAtr(1)) + two.getAtr(0) *(three.getAtr(1) - one.getAtr(1)) + three.getAtr(0) * (one.getAtr(1) - two.getAtr(1))));
}

int findM(Point one, Point two)
{

	int m = (int)roundf(((two.getAtr(1) - one.getAtr(1)) / (two.getAtr(0) - one.getAtr(0))) * (1 << 8));
	return(m);
}

int findB(Point one, int m)
{
	return ((int)roundf((-(m * one.getAtr(0)) + one.getAtr(1)) * (1 < 8)));
}


bool checkSameX(Point const a, Point const b, Point const c, Point const point)
{
	if (a.getAtr(0) == b.getAtr(0))
	{
		if (a.getAtr(1) > b.getAtr(1))
		{
			if ((point.getAtr(1) > a.getAtr(1)) || (point.getAtr(1) < b.getAtr(1)))
				return (true);
		}
		else
			if ((point.getAtr(1) > b.getAtr(1)) || (point.getAtr(1) < a.getAtr(1)))
				return (true);
	}
	else if (a.getAtr(0) == c.getAtr(0))
	{
		if (a.getAtr(1) > c.getAtr(1))
		{
			if ((point.getAtr(1) > a.getAtr(1)) || (point.getAtr(1) < c.getAtr(1)))
				return (true);
		}
		else
			if ((point.getAtr(1) > c.getAtr(1)) || (point.getAtr(1) < a.getAtr(1)))
				return (true);
	}
	else if (b.getAtr(0) == c.getAtr(0))
	{
		if (b.getAtr(1) > c.getAtr(1))
		{
			if ((point.getAtr(1) > b.getAtr(1)) || (point.getAtr(1) < c.getAtr(1)))
				return (true);
		}
		else
			if ((point.getAtr(1) > c.getAtr(1)) || (point.getAtr(1) < b.getAtr(1)))
				return (true);
	}
	return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	//checking the point is not on the point of triangle
	if ((point.getAtr(0) == a.getAtr(0) && point.getAtr(1) == a.getAtr(1))
		|| (point.getAtr(0) == b.getAtr(0) && point.getAtr(1) == b.getAtr(1))
		|| (point.getAtr(0) == c.getAtr(0) && point.getAtr(1) == c.getAtr(1)))
	{
		std::cout << "the point is out of triangle1!" << std::endl;
		return (false);
	}
	//checking whether you are trying to make a triangle by same points
	if ((a.getAtr(0) == b.getAtr(0) && a.getAtr(1) == b.getAtr(1))
		|| (a.getAtr(0) == c.getAtr(0) && a.getAtr(1) == c.getAtr(1))
		|| (b.getAtr(0) == c.getAtr(0) && b.getAtr(1) == c.getAtr(1)))
	{
		std::cout << "you can not built a triangle with these parametrs!" << std::endl;
		return (false);
	}

	int	a0 = area(a,b,c);
	//checking whether 3 points are on the same line
	if (a0 == 0)
	{
		std::cout << "you can not built a triangle with these parametrs!" << std::endl;
		return (false);
	}
	int	a1 = area(point, b, c);
	int	a2 = area(a,point,c);
	int	a3 = area(a, b, point);
	std::cout << point.getAtr(0) << std::endl;
	if (((a.getAtr(0) == b.getAtr(0)) || (b.getAtr(0) == c.getAtr(0))
		|| (a.getAtr(0) == c.getAtr(0))) && ((point.getAtr(0) == a.getAtr(0)) 
		|| (point.getAtr(0) == b.getAtr(0)) || (point.getAtr(0) == c.getAtr(0))))
	{
		std::cout << "the point is out of triangle2!" << std::endl;
		return (false);
	}
	if (checkSameX(a, b, c, point))
	{
		std::cout << "the point is out of triangle(on the edge)!" << std::endl;
		return (false);
	}
	int m1 = findM(a, b);
	int m2 = findM(a, c);
	int m3 = findM(c, b);
	std::cout << "aaaaaaaaa" <<std::endl;

	int b1 = findB(a, m1);
	int b2 = findB(b, m2);
	int b3 = findB(c, m3);


	//checking whether the Point is on the edge of triangle
	if ((point.getAtr(1) == (m1*point.getAtr(0)) + b1) || (point.getAtr(1) == (m2*point.getAtr(0)) + b2)
		|| (point.getAtr(1) == (m3*point.getAtr(0)) + b3))
	{
		std::cout << "the point is out of triangle2!" << std::endl;
		return (false);
	}
	//checking whether the point is in triangle
	else if (a0 == (a1 + a2 + a3))
	{
		std::cout << "the point is in the triangle!" << std::endl;
		return(true);
	}
	std::cout << "the point is out of triangle3!" << std::endl;
	return (false);
	
}