#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	int fixed;
	static const int bits = 8;
public:
	Fixed(); //default ctor
	Fixed(Fixed &other); //copy ctor
	Fixed &operator=(const Fixed &other); // assignment operator overload
	~Fixed();
	int		getRawBits();
	void	setRawBits(int const raw);
};

#endif
