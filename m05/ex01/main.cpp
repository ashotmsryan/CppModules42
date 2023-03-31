#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat ob("ash", 1);
	Form		f("paymanagir", 150, 150);

	std::cout << ob;
	try{
		ob.decrement();
	}
	catch(const std::exception &o)
	{
		std::cout << o.what() << std::endl;
	}

	std::cout << ob;
	try{
		ob.increment();
	}
	catch(const std::exception &o)
	{
		std::cout << o.what() << std::endl;
	}
	std::cout << ob;
	ob.signForm(f);
	f.beSigned(ob);
}