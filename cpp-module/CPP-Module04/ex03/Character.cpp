#include "Character.hpp"

Character::Character(void) : name("") {
	initInventory();
}

Character::Character(const std::string& name) 
	: name(name) {
	initInventory();
}

Character::Character(const Character& c) {
	*this = c;
}

Character& Character::operator=(const Character& c) {
	if (this == &c)
		return (*this);
	this->name = c.getName();
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		AMateria *(&amateria) = this->inventory[i];
		AMateria *oAmateria = c.inventory[i];
		if (amateria)
			delete amateria;
		amateria = NULL;
		if (oAmateria)
			amateria = oAmateria->clone();
	}
	return (*this);
}

Character::~Character(void) {
	for (int i = 0 ; i < INVENTORY_SIZE ; i++)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	std::cout << "Destruct Character" << std::endl;
}

void Character::initInventory(void) {
	for (int i = 0 ; i < INVENTORY_SIZE ; i++)
		this->inventory[i] = NULL;
}

const std::string& Character::getName(void) const {
	return (this->name);
}

void Character::equip(AMateria* a) {
	if (a == NULL)
		return ;
	for (int i = 0 ; i < INVENTORY_SIZE ; i++) {
		if (this->inventory[i] == 0) {
			this->inventory[i] = a->clone();
			std::cout << "success equip : " << this->inventory[i]->getType() << std::endl;
			return ;
		}
	}
	std::cout << "fail equip : " << a->getType() << " because full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > (INVENTORY_SIZE - 1)) {
		std::cout << "fail unequip because out of bind" << std::endl;
		return ;
	}
	if (this->inventory[idx] == 0) {
		std::cout << "That equipment doesn't exist." << std::endl;
		return ;
	}
	const std::string type = this->inventory[idx]->getType();
	delete this->inventory[idx];
	this->inventory[idx] = NULL;
	std::cout << "success unequip : " << type << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > (INVENTORY_SIZE - 1)) {
		std::cout << "out of bind" << std::endl;
		return ;
	}
	if (this->inventory[idx] == NULL) {
		std::cout << "This equipment does not exist " << std::endl;
		return ;
	}
	AMateria* a = this->inventory[idx];
	if (a)
		a->use(target);
	else
		std::cout << "The user does not exist" << std::endl;		
}