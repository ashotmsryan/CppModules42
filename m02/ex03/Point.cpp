#include "Point.hpp"

Point::Point():x(0),y(0){
	// std::cout << "default ctor called!" << std::endl;
	}
Point::Point(const float a, const float b):x(a),y(b){
	// std::cout << "param ctor called!" << std::endl;
	}
Point::Point(const Point &a):x(a.x),y(a.y){
	// std::cout << "copy ctor called!" << std::endl;
}
Point &Point::operator=(const Point &){return (*this);}
Point::~Point(){
	// std::cout << "dtor called!" << std::endl;
	}

int	Point::getAtr(int i)const
{
	switch (i)
	{
		case 0:
			return(this->x.getFixed());
		break;
		default :
			return(this->y.getFixed());
		break;
	}
}
