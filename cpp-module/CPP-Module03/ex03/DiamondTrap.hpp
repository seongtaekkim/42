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
        : ScavTrap(name), FragTrap(name)
    {
        this->_name = name +" d";
        std::cout << "create DiamondTrap " << name << std::endl;
        //init(name, 100, 100, 30);
    }
    DiamondTrap & operator = (const DiamondTrap & c)
    {
        //ClapTrap::operator =(c);
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
    virtual std::ostream& print(std::ostream& out) const 
    {
        out << "energyPoints : " << this->getEnergyPoints() << 
            " attackDamage : " << this->getAttackDamage() << 
            " hitPoints : " << this->getHitPoints();
        return (out);
    }
};
std::ostream & operator << (std::ostream &out, const DiamondTrap &c)
{
    return (c.print(out));
}

#endif