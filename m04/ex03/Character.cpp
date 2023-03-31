#include "Character.hpp"

Character::Character()
{
	for (size_t i = 0; i < 4; i++)
		this->arr[i] = 0;
	std::cout << "default ctor called for Character!" << std::endl;
}
Character::Character(Character &other)
{
	std::cout << "Copy ctor called for Character!" << std::endl;
	for (size_t i = 0; i < 4; i++)
		if (other.arr[i])
			this->arr[i] = other.arr[i]->clone();
	this->name = other.name;
}

Character::Character(std::string name)
{
	this->name = name;
	for (size_t i = 0; i < 4; i++)
		this->arr[i] = 0;
	std::cout << "param ctor called for Character!" << std::endl;
}

Character &Character::operator=(Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (size_t i = 0; i < 4; i++)
		{
			delete this->arr[i];
			this->arr[i] = 0;
		}
		for (size_t i = 0; i < 4; i++)
			if (other.arr[i])
				this->arr[i] = other.arr[i]->clone();
	}
	return (*this);
}

Character::~Character(){std::cout << "dtor called for Character!" << std::endl;}

/////////////////////////////////////////////////////////////////

std::string const &Character::getName() const{return (this->name);}
void	Character::equip(AMateria *m)
{
	int i = 0;
	if (m)
	{
		while(i != 4 && m != this->arr[i])
			i++;
		if (i != 4 && this->arr[i] && this->arr[i] == m)
		{
			std::cout << "same object input to equip()" << std::endl; 
			return ;
		}
		i = 0;
		while(i != 4 && this->arr[i])
			i++;
		if (this->arr[i] == 0)
		{
			this->arr[i] = m;
			return ;
		}
		std::cout << "no space left in inventory!" << std::endl;
	}
	else
		std::cout << "don't give me a NULL araa!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		this->arr[idx] = 0;
	}
	else
		std::cout << "too high/low index of obj!" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{

	if ((idx > -1 && idx < 4) && this->arr[idx])
		this->arr[idx]->use(target);
}