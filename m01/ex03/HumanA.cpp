#include "HumanA.hpp"
class Weapon;

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->gettype() << std::endl;
}

HumanA::HumanA(std::string name, Weapon club)
{
    this->weapon = &club;
    this->name = name;
}
