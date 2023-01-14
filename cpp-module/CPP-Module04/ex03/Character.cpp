#include "Character.hpp"

Character::Character(void) {

}
Character::Character(const std::string& name) {

}
Character::Character(const Character& c) {

}
Character::~Character(void) {

}
Character& Character::operator=(const Character& c) {

}
std::string const& Character::getName() const {

}
void Character::equip(AMateria* m) {

}
void Character::unequip(int idx) {

}
void Character::use(int idx, ICharacter& target) {

}