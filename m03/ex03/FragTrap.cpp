#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	this->setter(100, 1);
	this->setter(100, 2);
	this->setter(30, 3);
	std::cout << "ctor called for FragTrap!" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	this->setter(100, 1);
	this->setter(100, 2);
	this->setter(30, 3);
	std::cout << "param ctor called for FragTrap!" << std::endl;
	this->settern(name);
}

FragTrap::FragTrap(FragTrap &other):ClapTrap(other)
{
	this->settern(other.gettern());
	this->setter(other.getter(1), 1);
	this->setter(other.getter(2), 2);
	this->setter(other.getter(2), 2);
	std::cout << "copy ctor called for FragTrap!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &other)
{
	if (this != &other)
	{
		this->settern(other.gettern());
		this->setter(other.getter(1), 1);
		this->setter(other.getter(2), 2);
		this->setter(other.getter(2), 2);
	}
	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << "dtor called for FragTrap!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Giiiivvvvve mee High 5!" << std ::endl;
}