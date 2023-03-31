#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
class Fixed;

class Point
{
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point &other);
	Point(const float a, const float b);
	Point &operator=(const Point &);
	~Point();

	int getval() const;
	int getAtr(int i) const;
	// int getterY(Fixed &y) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif