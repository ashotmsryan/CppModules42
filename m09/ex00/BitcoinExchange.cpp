#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange::~BitcoinExchange()
{}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	this->map = other.map;
	this->fl = other.fl;
	this->str = other.str;
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		this->map = other.map;
		this->fl = other.fl;
		this->str = other.str;
	}
	return (*this);
}
///////////////////////////////////////////////////////////////////////////////

std::map<std::string, float> &BitcoinExchange::getMap(){return (this->map);}

void	BitcoinExchange::setStringFloat(std::string str, float val)
{
	this->map[str] = val;
}

void	BitcoinExchange::setFloat(float f){this->fl = f;}
float	BitcoinExchange::getFloat(){return (this->fl);}

void	BitcoinExchange::setString(std::string str){this->str = str;}
std::string	BitcoinExchange::getString(){return (this->str);}


void	 BitcoinExchange::firstLine(std::stringstream &str, int flag)
{
	std::string	a;
	while (str >> a)
	{
		flag++;
		if (flag == 1 && a != "date")
		{
			this->getMap().clear();
			std::cout << "not valid information in file-->> TRY WITH 'data | value' ON THE FIRST LINE1"<< std::endl;
			exit(1);
		}
		else if (flag == 2 && a != "|")
		{
			this->getMap().clear();
			std::cout << "not valid information in file-->> TRY WITH 'data | value' ON THE FIRST LINE2"<< std::endl;
			exit(1);
		}
		else if (flag == 3 && a != "value")
		{
			this->getMap().clear();
			std::cout << "not valid information in file-->> TRY WITH 'data | value' ON THE FIRST LINE3"<< std::endl;
			exit(1);
		}
	}
	if (flag != 3)
	{
		this->getMap().clear();
		std::cout << "not valid information in file-->> TRY WITH 'data | value' ON THE FIRST LINE3"<< std::endl;
		exit(1);
	}
}

bool	BitcoinExchange::rangeValidInt(std::string nmb)
{
	int n = std::atoi(nmb.c_str());

	int i = 0;
	while (nmb[i] && (nmb[i] == '+' || nmb[i] == '-' || nmb[i] == '0'))
		i++;
	std::string s = std::to_string(n);
	if(s == &nmb[i])
		return (false);
	return (true);
}

bool	BitcoinExchange::rangeValidFloat(std::string nmb)
{
	double n = std::atof(nmb.c_str());

	int i = 0;
	while (nmb[i] && (nmb[i] == '+' || nmb[i] == '-' || nmb[i] == '0'))
		i++;
	std::string s = std::to_string(n);
	if(s == &nmb[i])
		return (false);
	return (true);
}

bool	BitcoinExchange::firstParam(std::string a)
{
	std::stringstream s(a);
	int flag = 0;
	std::string token;
	int month = 0;
	int year = 0;
	int day = 0;
	while (getline(s, token, '-'))
	{
		if (flag == 0)
		{
			year = atoi(token.c_str());
			if (rangeValidInt(token) || (year < 2009 || year > 2022))
			{
				std::cout << "Error: bad input => " + a << std::endl;
				return (false);
			}
		}
		else if (flag == 1)
		{
			month = atoi(token.c_str());
			if (rangeValidInt(token) || (month > 12 || month < 1))
			{
				std::cout << "Error: bad input => " + a << std::endl;
				return (false);
			}
		}
		else if (flag == 2)
		{
			day = atoi(token.c_str());
			if (rangeValidInt(token) || (day > 31 || day < 1))
			{
				std::cout << "Error: bad input => " + a << std::endl;
				return (false);
			}
			else if ((month == 4 || month == 6 
				|| month == 9 || month == 11) && day > 30)
			{
				std::cout << "Error: bad input => " + a << std::endl;
				return (false);
			}	
			else if (month == 2)
			{
				if (year % 4 == 0 && day > 29)
				{
					std::cout << "Error: bad input => " + a << std::endl;
					return (false);
				}
				else if (year % 4 != 0 && day > 28)
				{
					std::cout << "Error: bad input => " + a << std::endl;
					return (false);					
				}
			}
		}
		flag++;
	}
	return (true);
}

bool	BitcoinExchange::lastParam(std::string a)
{
	int flag_dot = 0;

	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == '-')
		{
			std::cout << "Error: not a positive number." << std::endl;
			return (false);
		}
		if (a[i] == '+' && ((a[i + 1] && !isdigit(a[i + 1])) || (!a[i + 1])))
		{
			std::cout << "Error: bad input => " + this->getString() << std::endl;
			return (false);
		}
		if (!isdigit(a[i]) && a[i] == '.')
			flag_dot++;
		if (!isdigit(a[i]) && a[i] != '+' && flag_dot != 1)
		{
			std::cout << "Error: bad input => " + this->getString() << std::endl;
			return (false);
		}
	}
	double f = atof(a.c_str());
	if (flag_dot == 1 && (f < std::numeric_limits<float>::min()))
	{
		std::cout << "Error: too large a number." << std::endl;
		return(false);		
	}
	if ((f >= 1000 || f <= 0) || (f > std::numeric_limits<float>::max()))
	{
		std::cout << "Error: too large a number." << std::endl;
		return(false);
	}
	return (true);
}

bool	BitcoinExchange::checkDataValue(std::stringstream &str)
{
	std::string a;
	int flag = 0;
	int check = 0;

	while (str >> a)
	{
		if (flag == 3)
			std::cout << "Error: too many parametrs" << std::endl;
		else if (flag == 0)
		{
			for (size_t i = 0; i < a.size(); i++)
			{
				if (!isdigit(a[i]) && a[i] != '-')
				{
					std::cout << "Error: bad input => " + a << std::endl;
					return (false);
				}
			}
			if (this->firstParam(a))
			{
				this->setString(a);
				check++;
			}
		}
		else if (flag == 1 && a != "|")
		{
			std::cout << "Error: bad input => " + this->getString() << std::endl;
			return (false);
		}
		else if (flag == 2 && check == 1)
		{
			if (this->lastParam(a))
			{
				this->setFloat(atof(a.c_str()));
				check++;
			}
		}
		flag++;
	}
	if (check == 2)
		return (true);
	return (false);
}

void	BitcoinExchange::getMapAndPars(char **argv)
{
	std::ifstream file;
	file.open(argv[1]);
	if (file.fail())
	{
		this->getMap().clear();
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}
	 if (file.peek() == std::ifstream::traits_type::eof())
        std::cout << "File is empty." << std::endl;
	std::string str;
	int flag = 0;
	while (std::getline(file, str))
	{
		std::stringstream ss(str);
		if (flag == 0)
			this->firstLine(ss, flag++);
		else
			if (this->checkDataValue(ss))
				this->findDateAndPrint();
	}
	file.close();
}

void	BitcoinExchange::findDateAndPrint()
{
	std::map<std::string, float>::iterator i = this->getMap().find(this->getString());
	if (i == this->getMap().end())
	{
		i = this->getMap().lower_bound(this->getString());
		if (i != map.begin())
			i--;
	}
	std::cout << i->first << " => " << this->getFloat() << " = " << (i->second * this->getFloat()) << std::endl;
}

float	BitcoinExchange::getRateOfBtc()
{
	std::ifstream fl;
	std::string str;
	std::string s;
	float		i = 0;

	fl.open("data.csv");
	if (fl.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}
	while(getline(fl, str))
	{
		size_t i = str.find(this->getString());
		if (i != std::string::npos)
		{
			s = str.substr(11, str.size());
			i = atof(s.c_str());
			i = i * this->getFloat();
		}
	}
	fl.close();
	return (i);
}

void	BitcoinExchange::getDataBase()
{
	std::ifstream file;
	file.open("data.csv");
	if (file.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}
	std::string str;
	while (std::getline(file, str))
	{
		size_t comma = str.find(",");
		this->setStringFloat(str.substr(0, comma), atof((str.substr(comma + 1, str.size())).c_str()));
	}
	file.close();
}