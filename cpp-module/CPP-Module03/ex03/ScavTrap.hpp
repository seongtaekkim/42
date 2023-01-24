#ifndef SCAV_TRAP_HPP
 #define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
protected:
	static const int SCAV_HP;
	static const int SCAV_EP;
	static const int SCAV_AD;
	ScavTrap(void);
public:
    ScavTrap(const std::string& name);
    ScavTrap& operator = (const ScavTrap& s);
    ScavTrap(const ScavTrap& s);
    virtual ~ScavTrap();
    virtual void attack(const std::string& target);
    void guardGate();
};

#endif