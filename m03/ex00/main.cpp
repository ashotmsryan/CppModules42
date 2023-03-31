#include "ClapTrap.hpp"

int main()
{
	ClapTrap	solder1;
	ClapTrap	solder2("davo");

	solder1.settern("ash");
	solder1.setter(5, 3);
	solder1.attack("davo");
	solder2.takeDamage(3);
	std::cout << solder2.getter(1) << std::endl;
	return (0);
}
