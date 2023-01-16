#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1("java");
	ClapTrap c2("spring");

	std::cout << std::endl;
	c1.beRepaired(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.attack(c1.getName());
	c2.takeDamage(5);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.beRepaired(3);
	c2.beRepaired(2);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(c1.getName());
	c1.takeDamage(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.beRepaired(10);
	c1.attack(c2.getName());
	std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(c1.getName());
	c1.takeDamage(5);
	std::cout << std::endl;


	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.attack(c1.getName());
	c2.beRepaired(3);
	return (0);

  return (0);
}