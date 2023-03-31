#include "Fixed.hpp"

Fixed::Fixed()//Fixed::Fixed():fixed(0){};
{
	std::cout << "Default constructor called" << std::endl; 
	this->fixed = 0;
}
Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}


Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl; 
	this->fixed = other.fixed;
}

Fixed::Fixed(const int nmb)
{
	std::cout << "Int constructor called" << nmb << std::endl;
	this->fixed = nmb << this->bits;
}

Fixed::Fixed(const float nmb)
{
	std::cout << "Float constructor called" << std::endl;
	
	this->fixed = (int)roundf((nmb * (1 << this->bits)));
}

float	Fixed::toFloat()
	const
{
	float f;

	f = ((float)(this->fixed) / (1 << this->bits));
	return(f);
}

int	Fixed::toInt()
	const
{
	return(this->fixed >> this->bits);
}

//operator <<
std::ostream &operator << (std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}
//operator =
Fixed& Fixed::operator =(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl; 
	if (this == &other)
		return (*this);
	this->fixed = other.fixed;
	return (*this);
}

//operator >
bool	Fixed::operator > (const Fixed &other){return (this->fixed > other.fixed);}

//operator <
bool	Fixed::operator < (const Fixed &other){return (this->fixed < other.fixed);}

//operator >=
bool	Fixed::operator >= (const Fixed &other){return (this->fixed >= other.fixed);}

//operator <=
bool	Fixed::operator <= (const Fixed &other){return (this->fixed <= other.fixed);}

//operator ==
bool	Fixed::operator == (const Fixed &other){return (this->fixed == other.fixed);}

//operator !=
bool	Fixed::operator != (const Fixed &other){return (this->fixed != other.fixed);}

//operator +
Fixed Fixed::operator + (const Fixed &other){return (this->toFloat() + other.toFloat());}

//operator -
Fixed Fixed::operator - (const Fixed &other){return (this->toFloat() - other.toFloat());}

//operator *
Fixed Fixed::operator * (const Fixed &other){return (this->toFloat() * other.toFloat());}

//operator /
Fixed Fixed::operator / (const Fixed &other){return (this->toFloat() / other.toFloat());}

//operator ++i
Fixed	&Fixed::operator ++(void){this->fixed = this->fixed + 1;; return (*this);}

//operator --i
Fixed	&Fixed::operator --(void){this->fixed = this->fixed - 1; return (*this);}

//operator i++
Fixed	Fixed::operator ++(int)
{
	Fixed tmp = *this;

	this->fixed = this->fixed + 1; 
	return (tmp);
}
//operator i--
Fixed	Fixed::operator --(int)
{
	Fixed tmp = *this;

	this->fixed = this->fixed - 1;
	return (tmp);
}

//min-max
Fixed	&Fixed::min(Fixed &s1, Fixed &s2){return (s1.fixed > s2.fixed ? s2 : s1);}
Fixed	&Fixed::max(Fixed &s1, Fixed &s2){return (s1.fixed > s2.fixed ? s1 : s2);}

//const min-max
const Fixed	&Fixed::min(const Fixed &s1, const Fixed &s2){return (s1.fixed > s2.fixed ? s2 : s1);}
const Fixed	&Fixed::max(const Fixed &s1, const Fixed &s2){return (s1.fixed > s2.fixed ? s1 : s2);}