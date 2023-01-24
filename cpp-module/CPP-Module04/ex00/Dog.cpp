#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& d) {
    std::cout << "Copy constructor called" << std::endl;
    *this = d;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& d) {
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this == &d)
        return (*this);
    return (*this);
}

void Dog::makeSound() const {
	std::cout << "bark" << std::endl;
}