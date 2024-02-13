#include "Cure.hpp"

Cure::Cure():AMateria()
{
	this-> type = "cure";
	std::cout << "default ctor called for Cure!" << std::endl;
}

Cure::~Cure()
{
	std::cout << "dtor called for Cure!" << std::endl;
}

Cure::Cure(std::string const &type):AMateria(type)
{
	std::cout << "param ctor called for Cure!" << std::endl;
}

Cure &Cure::operator=(Cure &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

Cure::Cure(Cure &other) : AMateria(other)
{
	std::cout << "copy ctor called for Cure!" << std::endl;
	*this = other;
}
///////////////////////////////////////////////////////////

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName()  << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	AMateria *a;
	
	a = new Cure();
	return (a);
}
