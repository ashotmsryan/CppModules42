#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("anun", 25, 5), target("")
{
	std::cout << "default ctor called for Presidential" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string tg):AForm("anun", 25, 5)
{
	this->target = tg;
	std::cout << "param ctor called for Presidential" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){std::cout << "de-ctor called for Presidential" << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other):AForm(other.getName(), other.getGrade(), other.getGradeExe())
{
	std::cout << "copy ctor called for Presidential" << std::endl;
	this->target = other.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);	
}
/////////////////////////////////////////////////////////////////
std::string PresidentialPardonForm::getTarget(){return(this->target);}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() && executor.getGrade() < this->getGrade())
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
