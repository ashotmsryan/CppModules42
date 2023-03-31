#include "Zombie.hpp"

int main()
{
    Zombie *p = zombieHorde(5, "ashot");
    for (int i = 0; i < 5; i++)
        p[i].announce();
    delete[] p;
    while(1);
    return (0);
}