#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("anun", 72, 45), target("")
{
	std::cout << "default ctor called for Robotomy" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string tg):AForm("anun", 72, 45)
{
	this->target = tg;
	std::cout << "param ctor called for Robotomy" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "de-ctor called for Robotomy" << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other):AForm(other.getName(), other.getGrade(), other.getGradeExe())
{
	std::cout << "copy ctor called for Robotomy" << std::endl;
	this->target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	if (this != &other)
		this->target = other.target;
	return (*this);	
}
////////////////////////////////////////////////////////////////

std::string RobotomyRequestForm::getTarget()const{return(this->target);}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() && executor.getGrade() < this->getGrade())
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		throw(AForm::CuldNotExec());
}
