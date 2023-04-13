#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(RPN const &other)
{
	this->numbers = other.numbers;
}

RPN &RPN::operator=(RPN const &other)
{
	if(this != &other)
	{
		this->numbers = other.numbers;
	}
	return (*this);
}
//////////////////////////////////////////////////////////

std::stack<double> &RPN::getNumber() {return (this->numbers);}

void	RPN::setNumber(double n){this->numbers.push(n);}

void	RPN::plusOperation()
{
	double i = this->getNumber().top();
	this->getNumber().pop();
	double j = this->getNumber().top();
	this->getNumber().pop();
	this->setNumber(j + i);
}

void	RPN::minusOperation()
{
	double i = this->getNumber().top();
	this->getNumber().pop();
	double j = this->getNumber().top();
	this->getNumber().pop();
	this->setNumber(j - i);
}

void	RPN::multipleOperation()
{
	double i = this->getNumber().top();
	this->getNumber().pop();
	double j = this->getNumber().top();
	this->getNumber().pop();
	this->setNumber(j * i);
}

bool	RPN::divisionOperation()
{
	double i = this->getNumber().top();
	this->getNumber().pop();
	double j = this->getNumber().top();
	this->getNumber().pop();
	if (i != 0)
		this->setNumber(j / i);
	else
		return (false);
	return (true);
}

bool	RPN::checkValidationAndInsert(char **argv)
{
	std::string s = argv[1];

	for (size_t i = 0; s[i]; i++)
	{
		if ((s[i] > '9' || s[i] < '0') && s[i] != '+' && s[i] != '.'
			&& s[i] != '-' && s[i] != '*' && s[i] != '/' && !std::isspace(s[i]))
			return false;
	}
	for (size_t i = 0; s[i]; i++)
	{
		if (i != 0 && i != s.size() && i != (s.size() - 1) && isdigit(s[i])
			&& s[i + 1] == '.' && isdigit(s[i + 2]))
		{
			int g = 0;
			int j = i + 1;
			while (s[++j] && isdigit(s[j]))
				g++;
			g += 2; 
			std::string a = s.substr(i, g);
			float l = atof(a.c_str());
			if ((l < std::numeric_limits<float>::min()))
				return(false);		
			if ((l > 10 || l <= 0) || (l > std::numeric_limits<float>::max()))
				return(false);
			this->setNumber(l);
			i+=g;
		}
		else if (std::isspace(s[i]))
			continue ;
		else if (s[i] >= '0' && s[i] <= '9')
			this->setNumber(s[i] - 48);
		else if (s[i] == '+')
		{
			if (this->getNumber().empty() || this->getNumber().size() < 2)
				return false;
			this->plusOperation();
		}
		else if (s[i] == '-')
		{
			if (this->getNumber().empty() || this->getNumber().size() < 2)
				return false;
			this->minusOperation();
		}
		else if (s[i] == '*')
		{
			if (this->getNumber().empty() || this->getNumber().size() < 2)
				return false;
			this->multipleOperation();
		}
		else if (s[i] == '/')
		{
			if (this->getNumber().empty() || this->getNumber().size() < 2)
				return false;
			if (!this->divisionOperation())
				return false;
		}
		else
			return false;
	}
	return (true);
}