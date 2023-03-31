#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	this->setter(100, 1);
	this->setter(50, 2);
	this->setter(20, 3);
	std::cout << "default ctor called for ScavTrap!"<< std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->setter(100, 1);
	this->setter(50, 2);
	this->setter(20, 3);
	std::cout << "param ctor calld for ScavTrap!" << std::endl;
	this->settern(name);
}

ScavTrap &ScavTrap::operator =(ScavTrap &other)
{
	if(this != &other)
	{
		this->setter(other.getter(1), 1);
		this->setter(other.getter(2), 2);
		this->setter(other.getter(3), 3);
		this->settern(other.gettern());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "dtor called for ScavTrap!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getter(2) > 0 && this->getter(1) > 0)
	{
		std::cout << "ScavTrap " << this->gettern() << " attacks "<< target <<", causing " << this->getter(3) << " points of damage...ba axper jan!!" <<std::endl;
		this->setter((this->getter(2) - 1), 2);
	}
	else
		std::cout << "Not enough energy/hit points!"<< std::endl;
}

void	ScavTrap::guardGate(){std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;}