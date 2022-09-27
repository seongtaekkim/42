#include <iostream>
#include <string>

class ClapTrap
{
private:
 std::string _name;
 int _hitPoints;
 int _energyPoints;
 int _attackDamage;
public:
 ClapTrap()
 {
    this->_hitPoints = 10;
    this->_energyPoints = 10;
 }
 void attack(const std::string& target)
 {
    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
    std::cout << this->_name << " attacks " << target << " causing " << this->_hitPoints << std::endl;
 }
 void takeDamage(unsigned int amount)
 {

 }
 void beRepaired(unsigned int amount)
 {

 }

};


int main(void)
{
    return (0);
}