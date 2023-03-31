#include "Zombie.hpp"

void    Zombie::setter(std::string name){this->name = name;}
void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
