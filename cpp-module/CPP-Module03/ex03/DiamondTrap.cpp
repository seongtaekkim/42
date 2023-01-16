#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {}
DiamondTrap::DiamondTrap(const std::string &name)
	: ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
	this->_name = name;
	std::cout << "create DiamondTrap " << name << std::endl;
	init(name, FRAG_HP, SCAV_EP, FRAG_AD);
}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
	: ScavTrap(d), FragTrap(d) {
	*this = d;
	std::cout << "copy DiamondTrap " << d.getName() << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "die DiamondTrap " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& d) {
	ClapTrap::operator = (d);
	std::cout << "copy assignment DiamondTrap " << d.getName() << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void) {
	std::cout << this->_name << " " << this->getName() << std::endl;
}