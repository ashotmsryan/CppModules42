#include "ScavTrap.hpp"

int main()
{
	ScavTrap	solder1;
	ScavTrap	solder2("davo");

	solder1.settern("ash");
	solder1.attack("davo");
	solder2.takeDamage(20);
	std::cout << solder2.getter(1) << std::endl;
	return (0);
}
