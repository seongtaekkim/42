#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "create ScavTrap " << name << std::endl;
	init(name, 100, 50, 20);
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

ScavTrap::~ScavTrap()
{
	std::cout << "die ScavTrap" << this->_name << std::endl;
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