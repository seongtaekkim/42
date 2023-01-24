#ifndef DIAMOND_TRAP_HPP
 #define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
private:
    std::string _name;
	DiamondTrap(void);
public:
    DiamondTrap(const std::string& name);
    DiamondTrap& operator= (const DiamondTrap& d);
    DiamondTrap(const DiamondTrap& d);
    virtual ~DiamondTrap(void);
    virtual void attack(const std::string& target);
    void whoAmI(void);
    virtual std::string getName() const;
};

#endif