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
 ClapTrap()
 {
  std::cout << "create ClapTrap" << std::endl;
 }
 ClapTrap(const std::string &name)
 {
   init(name + "_clap_name", 10, 10, 0);
   std::cout << "create " << this->_name << std::endl;
 }
 void init(const std::string &name, int hitPoints, int energyPoints, int attackDamage)
 {
  this->_name = name;
  this->_hitPoints = hitPoints;
  this->_energyPoints = energyPoints;
  this->_attackDamage = attackDamage;
 }
 ClapTrap(const ClapTrap & c)
 {
   this->_name = c._name;
   this->_hitPoints = c._hitPoints;
   this->_energyPoints = c._energyPoints;
   this->_attackDamage = c._attackDamage;
 }
 virtual ~ClapTrap()
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
 virtual void attack(const std::string& target)
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
 int getHitPoints() const
 {
  return (this->_hitPoints);
 }
 int getEnergyPoints() const
 {
  return (this->_energyPoints);
 }
/*  virtual std::ostream& print(std::ostream& out) const
 {
     out << "energyPoints : " << this->getEnergyPoints() << 
           " attackDamage : " << this->getAttackDamage() << 
           " hitPoints : " << this->getHitPoints();
      return (out);
 } */
};

// std::ostream & operator << (std::ostream &out, const ClapTrap &c)
// {
//     return (c.print(out));
// }

#endif