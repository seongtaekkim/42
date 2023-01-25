
#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &a) {
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator = (const Animal &a) {
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this == &a)
        return (*this);
    return (*this);
}

void Animal::makeSound() const {
	std::cout << "Anmimal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}

std::ostream& operator<< (std::ostream& out, const Animal& a) {
    out << a.getType();
    return (out);
}