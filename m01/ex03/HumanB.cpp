#include "HumanB.hpp"
class Weapon;

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->gettype() << std::endl;
}

void    HumanB::setWeapon(Weapon club){this->weapon = &club;}

HumanB::HumanB(std::string name){this->name = name;}