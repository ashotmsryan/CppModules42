// // #include "Array.hpp"

// template<class T>Array<T>::Array()
// {
// 	this->arr = 0;
// 	std::cout << "default ctor called!"	<< std::endl;
// }

// template<class T>Array<T>::Array(int i)
// {
// 	this->arr = new (i+1) (T);
// 	arr[i + 1] = 0;
// 	std::cout << "param ctor called!" << std::endl;
// }

// template<class T>Array<T>::Array(Array const &other)
// {
// 	if (other.arr)
// 	{
// 		size_t i = 0;
// 		while (other.arr[i])
// 			i++;
// 		this->arr = new (i + 1)(T);
// 		for (size_t i = 0; other.arr[i]; i++)
// 			this->arr[i] = other.arr[i];
// 		this->arr[i + 1] = 0;
// 	}
// }

// Array &template<class T>Array<T>::operator=(Array const &other)
// {
// 	if (this != &other)
// 	{
// 		delete this->arr;
// 		size_t i = 0;
// 		while (other.arr[i])
// 			i++;
// 		this->arr = new (i + 1)(T);
// 		for (size_t i = 0; other.arr[i]; i++)
// 			this->arr[i] = other.arr[i];
// 		this->arr[i + 1] = 0;
// 	}
// 	return (*this)
// } 

// template<class T>Array<T>::~Array()
// {
// 	delete this->arr;
// }