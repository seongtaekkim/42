#include "Zombie.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "please input number of zombie !" << std::endl;
        return (0);
    }
    int n = std::atoi(argv[1]);
    Zombie *z = zombieHorde(n, "zombie");
    int index = 0;
    while (index < n)
    {
        z[index].announce();
        index++;
    }
    delete [] z;
    return (0);
}
