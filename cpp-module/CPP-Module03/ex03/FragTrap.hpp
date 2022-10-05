#ifndef FRAG_TRAP_HPP
 #define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(const std::string &name)
        : ClapTrap()
    {
        std::cout << "create FragTrap " << name << std::endl;
        init(name, 100, 100, 30);
    }
    FragTrap & operator = (const FragTrap & c)
    {
        ClapTrap::operator =(c);
        std::cout << "assign copy FragTrap " << c.getName() << std::endl;
        return (*this);
    }
    FragTrap(const FragTrap &c)
        : ClapTrap(c)
    {
        *this = c;
        std::cout << "copy FragTrap " << c.getName() << std::endl;
    }
    ~FragTrap()
    {
        std::cout << "die FragTrap " << this->getName() << std::endl;
    }
    void highFivesGuys(void)
    {
        std::cout << "lets high fives !" << std::endl;
    }
    /* virtual std::ostream& print(std::ostream& out) const
    {
        out << "energyPoints : " << this->getEnergyPoints() << 
            " attackDamage : " << this->getAttackDamage() << 
            " hitPoints : " << this->getHitPoints();
        return (out);
    } */
};

#endif