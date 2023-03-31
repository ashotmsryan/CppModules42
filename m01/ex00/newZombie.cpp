#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *ero = new (Zombie);

    ero->setter(name);
    return (ero);
}