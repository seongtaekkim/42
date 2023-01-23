#include "Zombie.hpp"

Zombie* newZombie(const std::string &name)
{
    Zombie *z;
    
    try
    {
        z = new Zombie(name);
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
        return (NULL);
    }
    return (z);
}
