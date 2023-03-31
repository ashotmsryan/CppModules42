#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    std::string name;
    int  hitPoint;
    int  ePoint;
    int  damage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap &other);
    virtual ~ClapTrap();
    ClapTrap &operator =(ClapTrap &other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    void setter(int val, int i);
    void settern(std::string name);
    int getter(int i);
    std::string gettern();
};

#endif