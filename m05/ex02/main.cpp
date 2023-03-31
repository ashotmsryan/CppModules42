#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat	ob("davo", 1);
	ShrubberyCreationForm		*f = new ShrubberyCreationForm("ash");

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
	ob.signForm(*f);
	f->beSigned(ob);
	try{
		f->execute(ob);
	}
	catch(std::exception &o)
	{
		std::cout << o.what()<< std::endl;
	}
	delete f;
}