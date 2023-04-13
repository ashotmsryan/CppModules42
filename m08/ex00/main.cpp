#include "easyfind.hpp"

int main()
{
	std::vector<int> a(5, 0);
	std::list<int> s;
	s.push_back(5);
	s.push_back(3);
	s.push_back(1);
	s.push_back(0);
	s.push_back(8);
	s.push_back(4);

	try{
		easyfind(s, 89);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	a.push_back(4);
	try
	{
		easyfind(a, 4);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}