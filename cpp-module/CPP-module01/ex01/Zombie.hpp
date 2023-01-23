#ifndef ZOMBIE_H
 #define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    ~Zombie();
    void    announce(void);
    void    setName(const std::string &name);
};
Zombie* zombieHorde(int N, std::string name);
Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);
#endif
