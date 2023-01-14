
#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &f) {
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this == &f)
        return (*this);
    return (*this);
}

void Dog::makeSound() const {
	std::cout << "bark" << std::endl;
}