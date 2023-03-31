
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
class Zombie
{
    std::string name;
public:
    ~Zombie();
    void        setter(std::string name);
    void        announce();

};
void    randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
