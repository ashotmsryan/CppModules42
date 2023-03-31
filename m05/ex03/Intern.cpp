#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern(){std::cout << "default ctor called for Intern" << std::endl;}
Intern::Intern(Intern &){std::cout << "copy ctor called for Intern" << std::endl;}
Intern &Intern::operator=(Intern &other){return (other);}
Intern::~Intern(){std::cout << "de=ctor called for Intern" << std::endl;}

const char *Intern::canNotMakeForm::what()const throw(){return ("netu takoy formtype!");}

AForm *Intern::makeShr(std::string target)
{
	std::cout << "Intern created a ShrubberyCreationForm!" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRob(std::string target)
{
	std::cout << "Intern created a RobotomyRequestForm!" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePre(std::string target)
{
	std::cout << "Intern created a PresidentialPardonForm!" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string n[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(Intern::*func[3])(std::string target) = {&Intern::makeShr, &Intern::makeRob, &Intern::makePre};

	for (int i = 0; i < 3; i++)
	{
		if (n[i] == name)
			return ((this->*func[i])(target));
	}
	throw(Intern::canNotMakeForm());
}