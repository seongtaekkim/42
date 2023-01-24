#ifndef FRAG_TRAP_HPP
 #define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
	static const int FRAG_HP;
	static const int FRAG_EP;
	static const int FRAG_AD;
	FragTrap(void);
public:
    FragTrap(const std::string& name);
    FragTrap& operator = (const FragTrap& c);
    FragTrap(const FragTrap& c);
    virtual ~FragTrap(void);
    void highFivesGuys(void);
};

#endif