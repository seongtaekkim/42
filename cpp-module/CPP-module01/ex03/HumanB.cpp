
#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
    : name(name)
{}
void    HumanB::attack()
{
    std::cout << this->name << " attack with his " << this->weapon->getType() << std::endl;
}
void    HumanB::setWeapon(Weapon &club)
{
    this->weapon = &club;

    std::cout << "humunb " <<  &club << std::endl;
    std::cout << "humunb " <<  weapon << std::endl;
}
