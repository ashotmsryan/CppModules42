#include "AForm.hpp"

AForm::AForm():name(""), grade(1), grade_exe(1)
{
	this->sign = false;
	std::cout << "default ctor called for Form!" << std::endl;
}

AForm::AForm(std::string nm, int gd, int gd_exe):name(nm), grade(gd), grade_exe(gd_exe)
{
	this->sign = false;
	if (gd > 150 || gd < 1)
	{
		gd = 150;
		throw("Grade of Form can not be higher/lower than 1/150");
	}
	if (gd_exe > 150 || gd_exe < 1)
	{
		gd_exe = 150;
		throw("Grade_exe of Form can not be higher/lower than 1/150");
	}
	std::cout << "param ctor called for Form!" << std::endl;
}

AForm::~AForm(){std::cout << "de-ctor called!" << std::endl;}

AForm::AForm(AForm &other):name(other.name), grade(other.grade), grade_exe(other.grade_exe)
{
	this->sign = other.sign;
	std::cout << "copy ctor called for Form!" << std::endl;
}

AForm &AForm::operator=(AForm &other)
{
	if (this != &other)
		this->sign = other.sign;
	return (*this);
}

int		AForm::getGrade()const {return (this->grade);}
const	std::string AForm::getName()const {return (this->name);}
int		AForm::getGradeExe()const {return (this->grade_exe);}
bool	AForm::getSign()const {return (this->sign);}
/// //////////////////////////////////////////////////////////////////////

const char *AForm::CuldNotExec::what() const throw(){return ("Grade is high/low or the form is unsigned, so, can not execute");}
const char *AForm::GradeTooLowException::what() const throw(){return ("Grade of Form can't be lower than 150");}
const char *AForm::GradeTooHighException::what() const throw(){return ("Grade of Form can't be higher than 1");}

std::ostream &operator <<(std::ostream &out, AForm &ob)
{
	out << "Name is " << ob.getName() << std::endl;
	out << "Grade is " << ob.getGrade() << std::endl;
	out << "Grade exe is " << ob.getGradeExe() << std::endl;
	out << "Sign is " << ob.getSign() << std::endl;
	return (out);
}

void	AForm::beSigned(Bureaucrat &ob)
{
	if (this->grade > ob.getGrade())
		this->sign = true;
	ob.signForm(*this);
}