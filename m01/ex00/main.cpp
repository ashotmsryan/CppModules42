#include "Zombie.hpp"

int main()
{
    std::string name = "suren";
    Zombie *p;

    randomChump(name);

    p = newZombie(name);
    p->announce();

    delete(p);
    return (0);
}