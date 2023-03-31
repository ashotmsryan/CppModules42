#include "FragTrap.hpp"

int main()
{
	FragTrap	solder1;
	FragTrap	solder2("davo");

	solder1.settern("ash");
	solder1.attack("davo");
	solder2.takeDamage(20);
	std::cout << solder2.getter(1) << std::endl;
	solder1.highFivesGuys();
	return (0);
}
