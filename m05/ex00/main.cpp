#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat ob("ash", 1);

	std::cout << ob;
	try{
		ob.increment();
	}
	catch(const std::exception &o)
	{
		std::cout << o.what() << std::endl;
	}
	std::cout << ob;
	try{
		ob.decrement();
	}
	catch(const std::exception &o)
	{
		std::cout << o.what() << std::endl;
	}
	std::cout << ob;
}