
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    std::string name;
public:
    void    setter(std::string name);
    void    announce();
};
Zombie* zombieHorde(int N, std::string name);

#endif