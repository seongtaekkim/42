
#include "DiamondTrap.hpp"
int main(void)
{
	DiamondTrap d("java");

	std::cout << std::endl;
	d.whoAmI();
	std::cout << std::endl;

	std::cout << "HP is " << d.getHitPoints() << std::endl;;
	std::cout << std::endl;

	std::cout << "EP is " << d.getEnergyPoints() << std::endl;;
	std::cout << std::endl;

	std::cout << "AD is " << d.getAttackDamage() << std::endl;;
	std::cout << std::endl;

	std::cout << std::endl;
	d.attack(d.getName());
	std::cout << std::endl;

	return (0);

  return (0);
}