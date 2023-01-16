#ifndef FRAG_TRAP_HPP
 #define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private:
	FragTrap(void);
protected:
	static const int FRAG_HP = 100;
	static const int FRAG_EP = 100;
	static const int FRAG_AD = 30;
public:
    FragTrap(const std::string& name);
    FragTrap & operator = (const FragTrap& c);
    FragTrap(const FragTrap& c);
    ~FragTrap(void);
    void highFivesGuys(void);
};

#endif