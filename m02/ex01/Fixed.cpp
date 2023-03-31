#include "Fixed.hpp"

Fixed::Fixed()//Fixed::Fixed():fixed(0){};
{
	std::cout << "Default constructor called" << std::endl; 
	this->fixed = 0;
}

Fixed& Fixed::operator =(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl; 
	if (this == &other)
		return (*this);
	this->fixed = other.fixed;
	return (*this);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl; 
	this->fixed = other.fixed;
}

Fixed::Fixed(const int nmb)
{
	std::cout << "Int constructor called" << std::endl;
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

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}


std::ostream &operator << (std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}