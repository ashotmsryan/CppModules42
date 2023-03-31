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
	int		getRawBits();
	void	setRawBits(int const raw);

	bool	operator > (const Fixed &other);
	bool	operator < (const Fixed &other);
	bool	operator >= (const Fixed &other);
	bool	operator <= (const Fixed &other);
	bool	operator == (const Fixed &other);
	bool	operator != (const Fixed &other);

	Fixed	operator + (const Fixed &other);
	Fixed	operator - (const Fixed &other);
	Fixed	operator * (const Fixed &other);
	Fixed	operator / (const Fixed &other);

	Fixed	&operator ++(void);
	Fixed	&operator --(void);
	Fixed	operator ++(int);
	Fixed	operator --(int);
	static Fixed	&min(Fixed &s1, Fixed &s2);
	static Fixed	&max(Fixed &s1, Fixed &s2);
	static const Fixed	&min(const Fixed &s1, const Fixed &s2);
	static const Fixed	&max(const Fixed &s1, const Fixed &s2);
};
std::ostream &operator <<(std::ostream &out, const Fixed &other); //insertion operator overload

#endif