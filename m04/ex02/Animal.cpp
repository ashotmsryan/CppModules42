#include "Animal.hpp"

Animal::Animal(){std::cout << "default ctor called for Animal!" << std::endl;}
Animal::~Animal(){std::cout << "dctor called for Animal!" << std::endl;}
Animal::Animal(const Animal &other){this->type = other.type;}

const Animal &Animal::operator=(const Animal &other)
{	
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

void	Animal::makeSound()const {std::cout << "netu axper jan" << std::endl;}

void	Animal::setter(std::string type){this->type = type;}
std::string Animal::getType()const {return (this->type);}