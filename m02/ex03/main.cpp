#include "Point.hpp"

int main( void ) 
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// 
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;

	Point a(1, 1);
	Point b(1, 2);
	Point c(0, 2);
	Point point(1.5, 1.5);

    //I tried to write my own bsp function
	bsp(a,b,c,point);

	return 0;
}