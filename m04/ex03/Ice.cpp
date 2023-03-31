#include "Ice.hpp"

Ice::Ice():AMateria()
{
	this->type = "ice";
	std::cout << "default ctor called for Ice!" << std::endl;
}

Ice::~Ice()
{
	std::cout << "dtor called for Ice!" << std::endl;
}

Ice::Ice(std::string const &type):AMateria(type)
{
	std::cout << "param ctor called for Ice!" << std::endl;
}

Ice &Ice::operator=(Ice &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

Ice::Ice(Ice &other)
{
	std::cout << "copy ctor called for Ice!" << std::endl;
	*this = other;
}
///////////////////////////////////////////////////////////

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()  << " *" << std::endl;
}

AMateria *Ice::clone() const{return (new Ice());}