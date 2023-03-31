#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	int fixed;
	static const int bits = 8;
public:
	Fixed(); //default ctor
	Fixed(const Fixed &other); //copy ctor
	Fixed(const int nmb); //param ctor
	Fixed(const float nmb); //param ctor
	Fixed &operator=(const Fixed &other); // assignment operator overload
	~Fixed();//de-ctor
	float	toFloat() const;
	int		toInt() const;
	// int		getRawBits();
	// void	setRawBits(int const raw);
};
std::ostream &operator <<(std::ostream &out, const Fixed &other); //insertion operator overload

#endif
