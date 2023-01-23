#ifndef HUMANB_HPP
 #define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon      *weapon;
public:
    HumanB(const std::string name);
    void    attack();
    void    setWeapon(Weapon &club);
};

#endif