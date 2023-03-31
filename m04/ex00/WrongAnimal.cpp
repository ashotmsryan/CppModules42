#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){std::cout << "default ctor called for Animal!" << std::endl;}
WrongAnimal::~WrongAnimal(){std::cout << "dtor called for Animal!" << std::endl;}
WrongAnimal::WrongAnimal(const WrongAnimal &other){this->type = other.type;}

const WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this->type != other.type)
		this->type = other.type;
	return (*this);
}

void	WrongAnimal::makeSound() const{std::cout << "netu axper jan" << std::endl;}

void	WrongAnimal::setter(std::string type){this->type = type;}
std::string WrongAnimal::getType() const {return (this->type);}
