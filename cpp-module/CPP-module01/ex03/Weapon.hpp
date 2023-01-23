#ifndef WEAPON_HPP
 #define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string name;
public:
    Weapon(const std::string &name);
    void    setType(const std::string &name);
    const std::string& getType() const;
};

#endif
