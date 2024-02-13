#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->mozg = new Brain;
	std::cout << "default ctor called for Cat!" << std::endl;
}
Cat::~Cat()
{
	delete this->mozg;
	std::cout << "dctor called for Cat!" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "copy ctor called for Cat!" << std::endl;
	this->type = other.type;
	this->mozg = new Brain();
}

const Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

void	Cat::makeSound() const {std::cout << "meawwwwww erevi axper" << std::endl;}
void	Cat::setter(std::string type){this->type = type;}
std::string Cat::getType() const {return (this->type);}