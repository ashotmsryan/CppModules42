#include "Weapon.hpp"

void    Weapon::setType(std::string type){this->type = type;}
std::string Weapon::gettype(){return(this->type);}

Weapon::Weapon(std::string type){this->setType(type);}