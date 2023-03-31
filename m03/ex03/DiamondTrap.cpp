#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap((ClapTrap::gettern() + "_clap_name"))
{
	std::cout << "deault ctor called for DiamondTrap!" << std::endl;
	this->setter(FragTrap::getter(1), 1);
	this->setter(ScavTrap::getter(2), 2);
	this->setter(30, 3);
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap((name + "_clap_name"))
{
	std::cout << "param ctor called for DiamondTrap!" << std::endl;
	this->_name = name;
	this->setter(FragTrap::getter(1), 1);
	this->setter(ScavTrap::getter(2), 2);
	this->setter(30, 3);
}

DiamondTrap::DiamondTrap(DiamondTrap &other):ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	*this = other;
	std::cout << "copy ctor called for DiamondTrap!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->setter(other.getter(1), 1);
		this->setter(other.getter(2), 2);
		this->setter(other.getter(3), 3);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(){std::cout << "dtor called for DiamondTrap!" << std::endl;}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << this->_name << std::endl;
	std::cout << "ClapTrap's name is " << this->ClapTrap::gettern() << std::endl;
}

