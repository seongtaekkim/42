#include "ScavTrap.hpp"

const int ScavTrap::SCAV_HP = 100;
const int ScavTrap::SCAV_EP = 50;
const int ScavTrap::SCAV_AD = 20;

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "create default scavTrap" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "create ScavTrap " << name << std::endl;
	init(name, SCAV_HP, SCAV_EP, SCAV_AD);
}

ScavTrap::ScavTrap(const ScavTrap &s)
	: ClapTrap(s) {
	*this = s;
	std::cout << "copy ScavTrap " << s.getName() << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap& s) {
	ClapTrap::operator = (s);
	std::cout << "assign copy ScavTrap " << s.getName() << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "die ScavTrap " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0) {
		(this->_energyPoints)--;
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " 
		<< this->getAttackDamage() << " points of damage!"<< std::endl;
	} else
		std::cout << "not enough energy ! " << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "now gate keeper mode" << std::endl;
}