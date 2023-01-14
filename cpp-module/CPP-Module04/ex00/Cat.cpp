#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &f) {
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this == &f)
        return (*this);
    return (*this);
}

void Cat::makeSound() const {
	std::cout << "mewww" << std::endl;
}