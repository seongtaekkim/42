#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#define INVENTORY_SIZE 4

class Character : public ICharacter {
private:
	std::string name;
	AMateria* inventory[INVENTORY_SIZE];
	Character(void);
public:
	Character(const std::string& name);
	Character(const Character& c);
	Character& operator=(const Character& c);
	virtual ~Character(void);
	virtual const std::string& getName(void) const;
	virtual void equip(AMateria* a);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	void initInventory(void);
};

#endif