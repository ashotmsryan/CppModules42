#pragma once
#include <iostream>

template<class T> class Array
{
	T	*arr;
	size_t n;
public:
	Array()
	{
		n = 0;
		this->arr = 0;
	};
	Array(int n)
	{
		this->n = static_cast<size_t>(n);
		this->arr = new T[n];
		for (size_t i = 0; i < static_cast<size_t>(n); i++)
		{
			// std::cout << i << std::endl;
			arr[i] = 0;
		}
	};
	Array(Array const &other)
	{
		if (other.arr)
		{
			this->n = other.n;
			size_t i = 0;
			while (other.arr[i])
				i++;
			this->arr = new T[i + 1];
			for (size_t i = 0; other.arr[i]; i++)
				this->arr[i] = other.arr[i];
			this->arr[i + 1] = 0;
		}
	};
	Array &operator=(Array const &other)
	{
		if (this != &other)
		{
			this->n = other.n;
			delete this->arr;
			size_t i = 0;
			while (other.arr[i])
				i++;
			this->arr = new T[i + 1];
			for (size_t i = 0; other.arr[i]; i++)
				this->arr[i] = other.arr[i];
			this->arr[i + 1] = 0;
		}
		return (*this);
	};
	~Array(){delete (this->arr);};

	T &operator[](int index) const
	{
		if (index < 0 || index > static_cast<int>(n))
			throw std::out_of_range("out of range");

			return (this->arr[index]);
	};
	size_t size() const {return (this->n);};

};
