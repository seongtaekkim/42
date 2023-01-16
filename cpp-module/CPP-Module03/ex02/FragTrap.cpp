#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {}

FragTrap::FragTrap(const std::string& name) : ClapTrap() {
	std::cout << "create FragTrap " << name << std::endl;
	init(name, 100, 100, 30);
}

FragTrap& FragTrap::operator = (const FragTrap& c) {
	ClapTrap::operator =(c);
	std::cout << "assign copy FragTrap " << c.getName() << std::endl;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& c) : ClapTrap(c) {
	std::cout << "copy FragTrap " << c.getName() << std::endl;
	*this = c;
}

FragTrap::~FragTrap(void) {
	std::cout << "die FragTrap " << this->getName() << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "lets high fives !" << std::endl;
}