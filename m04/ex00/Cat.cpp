#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "default ctor called for Cat!" << std::endl;
}
Cat::~Cat(){std::cout << "dtor called for Cat!" << std::endl;}
Cat::Cat(const Cat &other)
{
	std::cout << "copy ctor called for Cat!" << std::endl;
	this->type = other.type;
}

const Cat &Cat::operator=(const Cat &other)
{
	if (this->type != other.type)
		this->type = other.type;
	return (*this);
}

void	Cat::makeSound() const {std::cout << "meawwwwww erevi axper" << std::endl;}
void	Cat::setter(std::string type){this->type = type;}
std::string Cat::getType() const {return (this->type);}