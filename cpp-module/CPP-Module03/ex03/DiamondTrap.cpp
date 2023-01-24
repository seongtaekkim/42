#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :  ClapTrap() {}
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name") {
	this->_name = name;
	std::cout << "create DiamondTrap " << name << std::endl;
	init(ClapTrap::_name, FRAG_HP, SCAV_EP, FRAG_AD);
}

DiamondTrap::DiamondTrap(const DiamondTrap &d) {
	*this = d;
	std::cout << "copy DiamondTrap " << d.getName() << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "die DiamondTrap " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& d) {
	if (this == &d)
		return (*this);
	ClapTrap::operator = (d);
	this->_name = d.getName();
	std::cout << "copy assignment DiamondTrap " << d.getName() << std::endl;
	return (*this);
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << this->_name << " " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName() const {
	return (this->_name);
}