#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
  FragTrap java("java");
  FragTrap spring("spring");

  java.attack(spring.getName());
  spring.takeDamage(java.getAttackDamage());
  java.beRepaired(5);
  java.highFivesGuys();
  

  return (0);
}