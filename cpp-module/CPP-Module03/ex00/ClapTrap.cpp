#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {}
ClapTrap::ClapTrap(const std::string &name) {
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "create " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) {
	this->_name = c._name;
	this->_hitPoints = c._hitPoints;
	this->_energyPoints = c._energyPoints;
	this->_attackDamage = c._attackDamage;
}

ClapTrap::~ClapTrap() {
	std::cout << "die " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap & c) {
	if (this == &c)
		return (*this);
	this->_name = c._name;
	this->_hitPoints = c._hitPoints;
	this->_energyPoints = c._energyPoints;
	this->_attackDamage = c._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0) {
		(this->_energyPoints)--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!"<< std::endl;
	} else
		std::cout << "not enough energy ! " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints = this->_hitPoints - amount;
	std::cout << this->_name << " took " << amount << " damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0) {
		this->_hitPoints += amount;
		(this->_energyPoints)--;
		std::cout << this->_name << " recovered " << amount << " hit point." << std::endl;
	} else 
		std::cout << "not enough energe" << std::endl;
}
 
std::string ClapTrap::getName() const {
	return (this->_name);
}

int ClapTrap::getAttackDamage() const {
	return (this->_attackDamage);
}