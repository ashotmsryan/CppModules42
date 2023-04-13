# pragma once

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	MutantStack(MutantStack const &other){this->c = other.c;};
	MutantStack &operator=(MutantStack const &other)
	{
		if (&other != this)
			this->c = other.c;
		return (*this);
	};
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();}
};
