#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange data;
		data.getDataBase();
		data.getMapAndPars(argv);
		data.getMap().clear();
	}
	else
		std::cout << "Error: could not open file." << std::endl;
}