#include "Form.hpp"

Form::Form():name(""), grade(1), grade_exe(1)
{
	this->sign = false;
	std::cout << "default ctor called for Form!" << std::endl;
}

Form::Form(std::string nm, int gd, int gd_exe):name(nm), grade(gd), grade_exe(gd_exe)
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

Form::~Form(){std::cout << "de-ctor called!" << std::endl;}

Form::Form(Form &other):name(other.name), grade(other.grade), grade_exe(other.grade_exe)
{
	this->sign = other.sign;
	std::cout << "copy ctor called for Form!" << std::endl;
}

Form &Form::operator=(Form &other)
{
	if (this != &other)
		this->sign = other.sign;
	return (*this);
}

int Form::getGrade(){return (this->grade);}
const std::string Form::getName(){return (this->name);}
int Form::getGradeExe(){return (this->grade_exe);}
bool	Form::getSign(){return (this->sign);}

const char *Form::GradeTooLowException::what() const throw(){return ("Grade of Form can't be lower than 150");}
const char *Form::GradeTooHighException::what() const throw(){return ("Grade of Form can't be higher than 1");}

std::ostream &operator <<(std::ostream &out, Form &ob)
{
	out << "Name is " << ob.getName() << std::endl;
	out << "Grade is " << ob.getGrade() << std::endl;
	out << "Grade exe is " << ob.getGradeExe() << std::endl;
	out << "Sign is " << ob.getSign() << std::endl;
	return (out);
}

void	Form::beSigned(Bureaucrat &ob)
{
	if (this->grade > ob.getGrade())
		this->sign = true;
	ob.signForm(*this);
}