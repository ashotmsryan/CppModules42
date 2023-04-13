#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <limits>

class BitcoinExchange
{
	float	fl;
	std::string str;
	std::map<std::string, float> map;
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange &operator=(BitcoinExchange const &other);
	~BitcoinExchange();

	std::map<std::string, float>	&getMap();
	void	setStringFloat(std::string str, float val);
	void	setFloat(float f);
	float	getFloat();
	void	setString(std::string str);
	std::string	getString();

	void	firstLine(std::stringstream &str, int flag);
	bool	firstParam(std::string a);
	bool	checkDataValue(std::stringstream &str);
	bool	lastParam(std::string a);
	bool	rangeValidInt(std::string nmb);
	bool	rangeValidFloat(std::string nmb);

	void	getMapAndPars(char **argv);
	void	findDateAndPrint();
	float	getRateOfBtc();
	void	getDataBase();

};