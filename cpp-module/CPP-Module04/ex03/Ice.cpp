#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(const Ice& i) : AMateria(i) {}
Ice::~Ice(void) {}
Ice& Ice::operator=(const Ice& i) {
	AMateria::operator=(i);
	return (*this);
}
AMateria* Ice::clone(void) const {
	return (new Ice(*this));
}
void Ice::use(const ICharacter& i) {
	std::cout << "* shoots an ice bolt at " << i.getName() << " *"<< std::endl;
}