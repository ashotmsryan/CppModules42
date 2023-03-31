#include "ClapTrap.hpp"

void	ClapTrap::settern(std::string name){this->name = name;}
void	ClapTrap::setter(int val, int i)
{
	switch (i)
	{
	case 1:
		this->hitPoint = val;
		break;
	case 2:
		this->ePoint = val;
		break;
	default:
		this->damage = val;
		break;
	}
}

std::string ClapTrap::gettern(){return(this->name);}

ClapTrap::ClapTrap()
{
	this->hitPoint = 10;
	this->ePoint = 10;
	this->damage = 0;
	std::cout << "default ctor called!"<< std::endl;
}

int ClapTrap::getter(int i)
{
        if (i == 1)
        	return(this->hitPoint);
        else if (i == 2)
  	    	return(this->ePoint);
   return(this->damage);
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "parametr ctor called!"<< std::endl;
	this->name = name;
	this->hitPoint = 10;
	this->ePoint = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	this->hitPoint = other.hitPoint;
	this->ePoint = other.ePoint;
	this->damage = other.damage;
	this->name = other.name;
	std::cout << "copy ctor called!" <<std::endl;
}

ClapTrap &ClapTrap::operator =(ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoint = other.hitPoint;
		this->ePoint = other.ePoint;
		this->damage = other.damage;
		std::cout << "operator = called!" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){std::cout << "dtor called !" << std::endl;}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ePoint > 0 && this->hitPoint > 0)
	{
		this->hitPoint += amount;
		this->ePoint--;
	}
	else
		std::cout << "Not enough energy/hit points!" << std::endl;	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint > (int)amount)
		this->hitPoint -= amount;
	else
		this->hitPoint = 0; 
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->ePoint > 0 && this->hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks "<< target <<", causing " << this->damage << " points of damage!" <<std::endl;
		this->ePoint--;
	}
	else
		std::cout << "Not enough energy/hit points!"<< std::endl;
}