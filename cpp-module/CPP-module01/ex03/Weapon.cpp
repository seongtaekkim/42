#include "Weapon.hpp"

Weapon::Weapon(const std::string &name)
    : name(name)
{}
void    Weapon::setType(const std::string &name)
{
    this->name = name;
}
std::string Weapon::getType() const
{
    return (this->name);
}