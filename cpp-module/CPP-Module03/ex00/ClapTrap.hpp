#ifndef CLAP_TRAP_HPP
 #define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
 std::string _name;
 int _hitPoints; // 체력 공격받으면-attackDamage 수리하면+amount
 int _energyPoints; // 공격,수리 시 -1
 int _attackDamage; // 공격력
public:
 ClapTrap(const std::string &name)
 {
   this->_name = name;
   this->_hitPoints = 10;
   this->_energyPoints = 10;
   this->_attackDamage = 0;
   std::cout << "create " << this->_name << std::endl;
 }
 ClapTrap(const ClapTrap & c)
 {
   this->_name = c._name;
   this->_hitPoints = c._hitPoints;
   this->_energyPoints = c._energyPoints;
   this->_attackDamage = c._attackDamage;
 }
 ~ClapTrap()
 {
   std::cout << "die " << this->_name << std::endl;
 }
 ClapTrap & operator = (const ClapTrap & c)
 {
   if (this == &c)
      return (*this);
   this->_name = c._name;
   this->_hitPoints = c._hitPoints;
   this->_energyPoints = c._energyPoints;
   this->_attackDamage = c._attackDamage;
   return (*this);
 }
 void attack(const std::string& target)
 {
    std::cout << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!"<< std::endl;
 }
 void takeDamage(unsigned int amount)
 {
  this->_hitPoints = amount - this->_hitPoints;
  std::cout << this->_name << " took " << amount << " damage." << std::endl;
 }
 void beRepaired(unsigned int amount)
 {
  this->_hitPoints += amount;
  std::cout << this->_name << " recovered " << amount << " hit point." << std::endl;
 }
 std::string getName() const
 {
  return (this->_name);
 }
 int getAttackDamage() const
 {
  return (this->_attackDamage);
 }
};

#endif