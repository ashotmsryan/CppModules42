#pragma once
#include <iostream>

# define BLACK	"\33[1;30m"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

template<class T> class Array
{
	T	*arr;
	size_t n;
public:
	Array()
	{
		this->arr = 0;
		n = 0;
	};
	Array(unsigned int n)
	{
		this->n = static_cast<size_t>(n);
		this->arr = new T[n];
	};
	Array(Array const &other)
	{
		this->n = other.n;
		this->arr = new T[this->n];
		for (size_t i = 0; i < this->n; i++)
			this->arr[i] = other.arr[i];
	};
	Array &operator=(Array const &other)
	{
		if (this != &other)
		{
			this->n = other.n;
			delete [] this->arr ;
			this->arr = new T[this->n];
			for (size_t i = 0; i < this->n; i++)
				this->arr[i] = other.arr[i]; 
		}
		return (*this);
	};
	~Array(){delete [] (this->arr);};

	T &operator[](int index) const
	{
		if (index < 0 || index >= static_cast<int>(n))
			throw std::out_of_range("out of range");

			return (this->arr[index]);
	};
	size_t size() const {return (this->n);};

};
