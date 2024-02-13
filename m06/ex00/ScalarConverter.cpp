#include "ScalarConverter.hpp"
char	*ScalarConverter::arg;
int ScalarConverter::i = 0;
char ScalarConverter::c = 0;
float ScalarConverter::f = 0;
double ScalarConverter::d = 0;
int ScalarConverter::i_flag = 1;
int ScalarConverter::c_flag = 1;
int ScalarConverter::f_flag = 1;
int ScalarConverter::d_flag = 1;

ScalarConverter::ScalarConverter()
{
	std::cout << "default ctor called!" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	std::cout << "copy ctor called!" << std::endl;
	this->arg = other.arg;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	std::cout << "assignment operator called!" << std::endl;
	if (this != &other)
		this->arg = other.arg;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "dtor called!" << std::endl;
}


bool IsDigit(std::string val)
{
	for (size_t i = 0; i != val.size(); i++)
	{
		if (!isdigit(val[i]))
		{
			if (i != 0 && val[i] && val[i] == '-');
			else
				return (false);
		}
	}
	return (true);
}
std::string orgnized(int i)
{
	if (isprint(i))
	{
		char a = i;
		std::string r = "'";
		r += a;
		r.push_back('\'');
		return (r);
	}
	else if (isascii(i) && !isprint(i))
		return ("Non displayable");
	else
		return ("impossible");
}



// void	ScalarConverter::checkType(std::string val)
// {
// 	// checkLimits(val);
// 	if (isFloatisDouble(val) == 1 && f_flag == 1)
// 	{
// 		float a;
// 		std::cout << val << std::endl;
// 		try
// 		{
// 			a = std::stof(val);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << "impossible" << '\n';
// 		}
		
// 		ScalarConverter::i = static_cast<int>(a);
// 		ScalarConverter::c = static_cast<char>(a);
// 		ScalarConverter::f = (float)std::stof(val);
// 		ScalarConverter::d = static_cast<double>(a);
// 	}
// 	else if (isFloatisDouble(val) == 2 && d_flag == 1)
// 	{
// 		double a = std::stod(val);
// 		ScalarConverter::i = static_cast<int>(a);
// 		ScalarConverter::c = static_cast<char>(a);
// 		ScalarConverter::f = (float)(a);
// 		ScalarConverter::d = a;
// 	}
// 	else if (IsDigit(val) && i_flag == 1)
// 	{
// 		int a = (int)std::stoi(val);
// 		if (isascii(a) && !isprint(a))
// 			c_flag = 3;
// 		else if (!isascii(a))
// 			c_flag = 2;
// 		//std::string s = val.append(".0");
// 		//std:: cout << s << std::endl;
// 		ScalarConverter::i = a;
// 		ScalarConverter::c = static_cast<char>(a);
// 		ScalarConverter::f = (float)(a);
// 		ScalarConverter::d = (double)(std::stod(val));
// 	}
// 	else if (!IsDigit(val) && val.size() > 1)
// 	{
// 		i_flag = 2;
// 		c_flag = 2;
// 		f_flag = 2;
// 		d_flag = 2;
// 	}
// 	else if (val.size() == 1 && !IsDigit(val))
// 	{
// 		char a = val[0];
// 		ScalarConverter::i = static_cast<int>(a);
// 		ScalarConverter::c = a;
// 		ScalarConverter::f = (float)(a);
// 		ScalarConverter::d = static_cast<double>(a);
// 	}

// }
//0 - neither double nor float
//1 - is float
//2 - is double 
int	isFloatisDouble(std::string val)
{
	int	i = 0;
	int checkDot = 0;
	int checkLet = 0;

	while (val[i])
	{
		if (i == 0 && val[i] && val[i] == '-')
			i++;
		else
		{
			if ((val[i] < '0' || val[i] > '9') && val[i] != '.' && val[i] != 'f')
					return (0);
			else if (val[i] == '.')
				checkDot++;
			else if (val[i] == 'f' && val.back() == 'f')
				checkLet++;
			i++;
		}
	}
	if (checkDot == 1 && checkLet == 1)
		return (1);
	else if (checkDot == 1 && checkLet == 0)
		return (2);
	return (0);
}
std::string ScalarConverter::checkChar(std::string val)
{
	if (IsDigit(val))
	{
		int i = atoi(ScalarConverter::arg);
		return (orgnized(i));
	}
	else if (isFloatisDouble(val) == 1)
	{
		float i = atof(ScalarConverter::arg);
		return (orgnized(static_cast<int>(i)));
	}
	else if (isFloatisDouble(val) == 2)
	{
		double i = atof(ScalarConverter::arg);
		return (orgnized(static_cast<int>(i)));
	}
	else if (!IsDigit(val) && val.size() > 1)
		return ("impossible");
	std::string s = "'";
	s += val;
	s.push_back('\'');
	return (s);
}

int ScalarConverter::checkInt(std::string val)
{
	if (isFloatisDouble(val) == 1)
	{
		float a = atof(ScalarConverter::arg);
		return (static_cast<int>(a));
	}
	else if (isFloatisDouble(val) == 2)
	{
		float a = atof(ScalarConverter::arg);
		return (static_cast<int>(a));
	}
	else if (IsDigit(val))
	{
		int a = atoi(ScalarConverter::arg);
		return (a);
	}
	else if (val.size() == 1 && isprint(val[0]))
	{
		char a = static_cast<char>(*(ScalarConverter::arg));
		return (a);
	}
	return (0);
}

// float ScalarConverter::checkFloat(std::string val)
// {
// 	if (isFloatisDouble(val))
// 		return (std::atof(arg));
// 	return (0);
// }

// void	checkAll(std::string val)
// {
// 	std::cout << std::numeric_limits<float>::max() << std::endl;
// }

void	ScalarConverter::convert(std::string val)
{
	ScalarConverter::arg = const_cast<char *>(val.c_str());
	// arr[3] = {"+inf", "-inf", "nan"};
	// std::cout << std::numeric_limits<float>::max() << std::endl;
	if (arg[0] == '+')
		arg++;
	// checkAll(val);
	//check char
	std::cout << "char: " << ScalarConverter::checkChar(val) << std::endl;
	//check int
	if (!isFloatisDouble(val) && !IsDigit(val) && !(val.size() == 1 && isprint(val[0])))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << ScalarConverter::checkInt(val) << std::endl;
	//check float
	if (isFloatisDouble(val))
	{	
		char *s;
		float a = strtof(arg, &s);
		if (errno == ERANGE)
			std::cout << "float: +inff/-inff" << std::endl;
		// else if (a < std::numeric_limits<float>::min() 
		// 	|| a > std::numeric_limits<float>::max())
		// 	std::cout << "float: -inff/+inff" << std::endl;
		else
			std::cout << "float: " << a << 'f' << std::endl;
	}
	else if (IsDigit(val))
		std::cout << "float: " << val << ".0f"<< std::endl;
	else
		std::cout << "float: nanf" << std::endl;
	//check double
	if (isFloatisDouble(val))
	{	
		char *s;
		double a = strtod(arg, &s);
		if (errno == ERANGE)
			std::cout << "double: +inf/-inf" << std::endl;
		// else if (a < std::numeric_limits<double>::min()
		// 	|| a > std::numeric_limits<double>::max())
		// 	std::cout << "double: -inf/+inf" << std::endl;
		else
			std::cout << "double: " << a << std::endl;
	}
	else if (IsDigit(val))
		std::cout << "double: " << val << ".0"<< std::endl;
	else
		std::cout << "double: nan" << std::endl;

}