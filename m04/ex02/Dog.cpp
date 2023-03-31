#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->mozg = new Brain;
	std::cout << "default ctor called for Dog!" << std::endl;
}
Dog::~Dog()
{
	delete this->mozg;
	std::cout << "dctor called for Dog!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "copy ctor called for Dog!" << std::endl;
	this->mozg = new Brain();
	this->type = other.type;
}

const Dog &Dog::operator=(const Dog &other)
{
	if (this->type != other.type)
		this->type = other.type;
	return (*this);
}

void	Dog::makeSound() const {std::cout << "bark bark bark erevi axper" << std::endl;}
void	Dog::setter(std::string type){this->type = type;}
std::string Dog::getType() const {return (this->type);}