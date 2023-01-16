#include "AMateria.hpp"

AMateria::AMateria(void) : type("") {}
AMateria::AMateria(const AMateria& a) {
	*this = a;
}
AMateria::AMateria(const std::string& type)
	: type(type) {}
AMateria::~AMateria(void) {}
AMateria& AMateria::operator=(const AMateria& a) {
	if (this == &a)
		return (*this);
	this->type = a.getType();
	return (*this);
}
const std::string& AMateria::getType(void) const {
	return (this->type);
}
void AMateria::use(const ICharacter& i) {
	(void)i;
}