#ifndef SCAV_TRAP_HPP
 #define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
	ScavTrap(void);
protected:
	static const int SCAV_HP = 100;
	static const int SCAV_EP = 50;
	static const int SCAV_AD = 20;
public:
    ScavTrap(const std::string& name);
    ScavTrap& operator = (const ScavTrap& s);
    ScavTrap(const ScavTrap& s);
    ~ScavTrap();
    virtual void attack(const std::string& target);
    void guardGate();
};

#endif