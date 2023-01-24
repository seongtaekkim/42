#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &w) {
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = w;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAminal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &w) {
    std::cout << "WrongAnimal Copy Assignment operator called" << std::endl;
    if (this == &w)
        return (*this);
    return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "wrong anmimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}