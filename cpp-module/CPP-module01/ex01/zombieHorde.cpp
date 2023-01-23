#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *zs;
    int     index;

    index = 0;
    zs = new Zombie[N];
    while (index < N)
    {
        zs[index].setName(name);
        index++;
    }
    return (zs);
}