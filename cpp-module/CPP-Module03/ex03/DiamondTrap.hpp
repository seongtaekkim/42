#ifndef DIAMOND_TRAP_HPP
 #define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
private:
    std::string _name;
public:
    DiamondTrap(const std::string &name)
        : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
    {
        this->_name = name;
        std::cout << "create DiamondTrap " << name << std::endl;
        init(name, FRAG_HP, SCAV_EP, FRAG_AD);
    }
    DiamondTrap & operator = (const DiamondTrap & c)
    {
        ClapTrap::operator =(c);
        // std::cout << "assign copy DiamondTrap " << c.getName() << std::endl;
        return (*this);
    }
    DiamondTrap(const DiamondTrap &c)
        : ScavTrap(c), FragTrap(c)
    {
        *this = c;
        std::cout << "copy DiamondTrap " << c.getName() << std::endl;
    }
    ~DiamondTrap()
    {
        std::cout << "die DiamondTrap " << this->_name << std::endl;
    }
    void whoAmI(void)
    {
        std::cout << this->_name << " " << this->getName() << std::endl;
    }
};

#endif