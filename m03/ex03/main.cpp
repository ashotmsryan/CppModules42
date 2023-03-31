#include "DiamondTrap.hpp"

int main()
{
	FragTrap	solder1;
	FragTrap	solder2("davo");

	solder1.settern("ash");
	solder1.attack("davo");
	solder2.takeDamage(20);
	std::cout << solder2.getter(1) << std::endl;
	solder1.highFivesGuys();

	DiamondTrap	a("ash");
	std::cout << "name = " << a.gettern() << std::endl;
	std::cout << "hit point = " << a.getter(1) << std::endl;
	std::cout << "energy point = " << a.getter(2) << std::endl;
	std::cout << "attack damage = " << a.getter(3) << std::endl;
	a.attack("Errrroooo");
	a.whoAmI();
	return (0);
}
