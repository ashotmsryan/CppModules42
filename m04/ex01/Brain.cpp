#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "default ctor called for Brain!" << std::endl;
}
Brain::~Brain(){std::cout << "dctor called for Brain!" << std::endl;}
Brain::Brain(const Brain &other)
{
	for(int i = 0; i != 100 ; i++)
		this->ideas[i] = other.ideas[i];
}

const Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
		for(int i = 0; i != 100 ; i++)
			this->ideas[i] = other.ideas[i];
	return (*this);
}