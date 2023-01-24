#ifndef FRAG_TRAP_HPP
 #define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
	FragTrap(void);
public:
    FragTrap(const std::string& name);
    FragTrap & operator = (const FragTrap& c);
    FragTrap(const FragTrap& c);
    virtual ~FragTrap(void);
    void highFivesGuys(void);
};

#endif