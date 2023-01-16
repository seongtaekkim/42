#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{

	ScavTrap t1("java");
	ScavTrap t2("spring");
	ClapTrap t3("cpp");

	std::cout << std::endl;
	t1.attack(t3.getName());
	t3.takeDamage(t1.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	t1.attack(t2.getName());
	t2.takeDamage(t1.getAttackDamage());
	t2.beRepaired(5);
	std::cout << std::endl;

	std::cout << std::endl;
	t1.attack(t3.getName());
	t2.takeDamage(t1.getAttackDamage());
	t1.attack(t3.getName());
	t2.takeDamage(t1.getAttackDamage());
	t1.attack(t3.getName());
	t2.takeDamage(t1.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	t2.guardGate();
	std::cout << std::endl;

	for (int i = 0 ; i < 50 ; i++)
		t1.attack(t3.getName());
	for (int i = 0 ; i < 50 ; i++)
		t2.beRepaired(5);
  	return (0);
}