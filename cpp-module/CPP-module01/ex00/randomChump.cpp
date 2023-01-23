#include "Zombie.hpp"

void    randomChump(const std::string &name)
{
    Zombie *z = newZombie(name);
    z->announce();
    try {
        delete (z);
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
}
