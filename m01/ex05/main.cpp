#include "Harl.hpp"

int main()
{
	std::string level;
	Harl		davo;

	std::cout << "Please, insert the level! -> "; 
	std::cin >> level;
	davo.complain(level);
	return (0);
}