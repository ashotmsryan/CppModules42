#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	const Brain &operator =(const Brain &other);
};

#endif