#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    std::string name;
    Weapon      *weapon;
public:
    HumanA(std::string name, Weapon club);
    void    attack();
};

#endif