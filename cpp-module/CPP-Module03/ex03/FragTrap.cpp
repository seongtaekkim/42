#include "FragTrap.hpp"

const int FragTrap::FRAG_HP = 100;
const int FragTrap::FRAG_EP = 100;
const int FragTrap::FRAG_AD = 30;

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "create default flagtrap" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap() {
	std::cout << "create FragTrap " << name << std::endl;
	init(name, FRAG_HP, FRAG_EP, FRAG_AD);
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
	std::cout << "lets high fivxes !" << std::endl;
}