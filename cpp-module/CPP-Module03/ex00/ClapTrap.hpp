#ifndef CLAP_TRAP_HPP
 #define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	ClapTrap(void);
public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& c);
	~ClapTrap();
	ClapTrap& operator = (const ClapTrap& c);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	int getAttackDamage() const;
};

#endif