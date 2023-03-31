#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->grade = 1;
	std::cout << "default ctor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g):name(n), grade(g)
{
	std::cout << "param ctor called!" << std::endl;
	try{
		if (this->grade > 150 || this->grade < 1)
			throw("Grade can't be lower than 1/ higher than 150");
	}
	catch(std::string m)
	{
		this->grade = 150;
		std::cout << m << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){std::cout << "de-ctor called!" << std::endl;}

Bureaucrat::Bureaucrat(Bureaucrat &other):name(other.name)
{this->grade = other.grade;}
Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw(){return ("Grade can't be higher than 150");}
const char	*Bureaucrat::GradeTooLowException::what() const throw(){return ("Grade can't be lower than 1");}


void Bureaucrat::increment()
{
	if (this->grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->grade -= 1;
}

void Bureaucrat::decrement()
{
	if (this->grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade += 1;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &ob)
{
	out << ob.getName() << ", bureaucrat grade " << ob.getGrade() << std::endl;
	return (out);
}

std::string Bureaucrat::getName()const{return (this->name);}
int Bureaucrat::getGrade()const{return (this->grade);}
