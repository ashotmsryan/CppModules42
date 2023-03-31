#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	AMateria *arr[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource &other);
	MateriaSource &operator=(MateriaSource const &other);
	~MateriaSource();
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};