#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string level;
		Harl		davo;

		level = argv[1];
		davo.complain(level);
	}
	else
		std::cout << "Wrong quantity of input!" << std::endl;
	return (0);
}