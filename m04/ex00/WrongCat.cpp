#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "default ctor called for WrongCat!" << std::endl;
}
WrongCat::~WrongCat(){std::cout << "dtor called for WrongCat!" << std::endl;}
WrongCat::WrongCat(const WrongCat &other){this->type = other.type;}

const WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this->type != other.type)
		this->type = other.type;
	return (*this);
}

void	WrongCat::makeSound() const {std::cout << "wrong meawwwwww erevi axper" << std::endl;}
void	WrongCat::setter(std::string type){this->type = type;}
std::string WrongCat::getType() const {return (this->type);}
