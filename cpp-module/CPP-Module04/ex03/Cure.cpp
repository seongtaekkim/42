#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(const Cure& c) : AMateria(c) {}
Cure::~Cure(void) {}
Cure& Cure::operator=(const Cure& c) {
	if (this == &c)
		return (*this);
	AMateria::operator=(c);
	return (*this);
}
AMateria* Cure::clone(void) const {
	return (new Cure(*this));
}
void Cure::use(const ICharacter& i) {
	std::cout << "* heals " << i.getName() << "'s wounds *" << std::endl;
}