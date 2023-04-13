#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	std::stack<double> numbers;
public:
	RPN();
	~RPN();
	RPN(RPN const &other);
	RPN &operator=(RPN const &other);

	std::stack<double>	&getNumber();
	void	setNumber(double n);

	bool	divisionOperation();
	void	multipleOperation();
	void	minusOperation();
	void	plusOperation();

	bool	checkValidationAndInsert(char **argv);
};