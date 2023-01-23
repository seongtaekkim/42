#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(const std::string name)
    : name(name) {}
Zombie::~Zombie() {
    std::cout << this->name << " is die." << std::endl;
}
void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
