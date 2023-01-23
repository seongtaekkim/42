#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
    : name(name), weapon(weapon)
{}

void    HumanA::attack()
{
    std::cout << this->name << " attack with his " << this->weapon.getType() << std::endl;
}
void    HumanA::setWeapon(const Weapon &club)
{
    this->weapon = club;
}
