#ifndef SCAV_TRAP_HPP
 #define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(const std::string &name)
        : ClapTrap()
    {
        std::cout << "create ScavTrap " << name << std::endl;
        init(name, 100, 50, 20);
    }
    ScavTrap & operator = (const ScavTrap & c)
    {
        ClapTrap::operator =(c);
        std::cout << "assign copy ScavTrap " << c.getName() << std::endl;
        return (*this);
    }
    ScavTrap(const ScavTrap &c)
        : ClapTrap(c)
    {
        *this = c;
        std::cout << "copy ScavTrap " << c.getName() << std::endl;
    }
    ~ScavTrap()
    {
        std::cout << "die ScavTrap " << this->getName() << std::endl;
    }
    virtual void attack(const std::string& target)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " 
        << this->getAttackDamage() << " points of damage!"<< std::endl;
    }
    void guardGate()
    {
        std::cout << "now gate keeper mode" << std::endl;
    }
};

#endif