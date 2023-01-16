#ifndef CLAP_TRAP_HPP
 #define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	int _hitPoints; // 체력 공격받으면-attackDamage 수리하면+amount
	int _energyPoints; // 공격,수리 시 -1
	int _attackDamage; // 공격력
	ClapTrap(void);
public:
	ClapTrap(const std::string& name);
	void init(const std::string& name, int hitPoints, int energyPoints, int attackDamage);
	ClapTrap(const ClapTrap& c);
	virtual ~ClapTrap();
	ClapTrap& operator = (const ClapTrap& c);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	int getAttackDamage() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
};

#endif