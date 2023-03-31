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
	Point b(2, 2);
	Point c(2, 3);
	Point point(1.5, 1.5);

	bsp(a,b,c,point);

	return 0;
}