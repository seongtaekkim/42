#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(3, *bob);

	me->unequip(2);
	me->unequip(2);
	delete bob;
	delete me;
	delete src;
	// system("leaks game");
	return (0);
}