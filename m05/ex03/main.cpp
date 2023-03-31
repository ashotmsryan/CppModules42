#include "AForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	ob("ash", 145);
	ShrubberyCreationForm		*f = new(ShrubberyCreationForm);
	Intern	inter;
	AForm	*ptr;

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
	ptr = inter.makeForm("RobotomyRequestForm", "davo");
	delete f;
	delete ptr;
}