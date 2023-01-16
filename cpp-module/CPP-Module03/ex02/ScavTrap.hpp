#ifndef SCAV_TRAP_HPP
 #define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	ScavTrap(void);
public:
    ScavTrap(const std::string& name);
    ScavTrap& operator = (const ScavTrap& s);
    ScavTrap(const ScavTrap& s);
    ~ScavTrap();
    virtual void attack(const std::string& target);
    void guardGate();
};

#endif