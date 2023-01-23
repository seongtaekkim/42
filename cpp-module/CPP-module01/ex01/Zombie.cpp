#include "Zombie.hpp"

Zombie::Zombie() {
        std::cout << "constructor zombie" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << this->name << " is die." << std::endl;
}
void    Zombie::setName(const std::string &name)
{
    this->name = name;
}
void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
