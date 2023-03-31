#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		this->arr[i] = 0;
	std::cout << "default ctor called for MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &other)
{
	std::cout << "copy ctor called for MateriaSource" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; this->arr[i]; i++)
		{
			delete this->arr[i];
			this->arr[i] = 0;
		}
		for (int i = 0; other.arr[i]; i++)
			this->arr[i] = other.arr[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource(){std::cout << "dtor called for MateriaSource!" << std::endl;}

// AMateria *MateriaSource::getMateria(int i)const {return (this->arr[i]);}

void	MateriaSource::learnMateria(AMateria *ob)
{
	static int i;
	if (i == 4)
		i = 0;
	this->arr[i] = ob;
	i++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	while(i < 4 && this->arr[i] && type != this->arr[i]->getType())
		i++;
	if (this->arr[i])
		return (this->arr[i]->clone());
	return (0);
}