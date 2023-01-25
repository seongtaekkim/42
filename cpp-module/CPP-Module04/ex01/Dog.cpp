#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->b = new Brain();
}

Dog::Dog(const Dog &d) {
    std::cout << "Dog Copy constructor called" << std::endl;
	this->b = new Brain();
    *this = d;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
	delete this->b;
}

Dog& Dog::operator = (const Dog& d) {
    std::cout << "Dog Copy Assignment operator called" << std::endl;
    if (this == &d)
        return (*this);
	if (this->b)
		delete this->b;
	b = new Brain(*d.b);
    return (*this);
}

void Dog::makeSound() const {
	std::cout << "bark" << std::endl;
}

const Brain* Dog::getIdeas() const {
	return (this->b);
}