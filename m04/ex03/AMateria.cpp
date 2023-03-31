#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

AMateria::AMateria()
{
	std::cout << "default ctor called for AMateria!" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << "param ctor called for AMateria!" << std::endl;
}
std::string const &AMateria::getType() const{return (this->type);}

AMateria::~AMateria(){std::cout << "dtor called for AMateria!" << std::endl;}

void	AMateria::use(ICharacter &target)
{	
	std::cout << "it is stupid to use a material without user on target ->!" << target.getName() << std::endl;
}