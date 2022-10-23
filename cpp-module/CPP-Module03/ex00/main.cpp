#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap java("java");
  ClapTrap spring("spring");

  java.attack(spring.getName());
  spring.takeDamage(java.getAttackDamage());
  java.beRepaired(5);

  return (0);
}