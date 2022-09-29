#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
  ScavTrap java("java");
  ScavTrap spring("spring");

  java.attack(spring.getName());
  spring.takeDamage(java.getAttackDamage());
  java.beRepaired(5);

  

  return (0);
}