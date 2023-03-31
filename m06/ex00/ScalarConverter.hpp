#pragma once

#include <iostream>
#include <cmath>

class ScalarConverter
{
	static char		*arg;
	static int		i;
	static char		c;
	static float	f;
	static double	d;

	//flags for nonprint
	static int		i_flag;
	static int		c_flag;
	static int		f_flag;
	static int		d_flag;

	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();
public:

	static void convert(std::string val);
	
	// static void checkType(std::string val);
	static std::string checkChar(std::string val);
	static int checkInt(std::string val);
	static float checkFloat(std::string val);
	
};