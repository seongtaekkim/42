#ifndef CLAP_TRAP_HPP
 #define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	ClapTrap(void);
public:
	ClapTrap(const std::string& name);
	void init(int hitPoints, int energyPoints, int attackDamage);
	ClapTrap(const ClapTrap& c);
	virtual ~ClapTrap();
	ClapTrap& operator = (const ClapTrap& c);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	int getAttackDamage() const;
};

#endif