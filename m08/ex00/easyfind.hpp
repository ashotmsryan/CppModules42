#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class exp : public std::exception
{
public:
	const char	*what() const throw()
	{
		return ("there is no such a numebr!");
	};
};

template<typename T>
void	easyfind(T &cont, int val)
{
	typename T::iterator ocur = std::find(cont.begin(), cont.end(), val);
	if (ocur != cont.end())
		std::cout << "the number " << *ocur << " found!" << std::endl;
	else
		throw exp();
}
