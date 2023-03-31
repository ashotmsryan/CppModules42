#include "Fixed.hpp"

Fixed::Fixed()//Fixed::Fixed():fixed(0){};
{
	std::cout << "Default constructor called" << std::endl; 
	this->fixed = 0;
}

Fixed::Fixed(Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl; 
	//this->fixed = other.getRawBits();
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "assignment operator has been called!" << std::endl; 
	if (this == &other)
		return (*this);
	this->fixed = other.fixed;
	return (*this);
}

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

int	Fixed::getRawBits()
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}
