#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->b = new Brain();
}

Cat::Cat(const Cat &f) {
    std::cout << "Cat Copy constructor called" << std::endl;
	this->b = new Brain();
    *this = f;
}

Cat::~Cat() {
	delete this->b;
    std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& c) {
    std::cout << "Cat Copy Assignment operator called" << std::endl;
    if (this == &c)
        return (*this);
	if (this->b)
		delete this->b;
	b = new Brain(*c.b);
    return (*this);
}

void Cat::makeSound() const {
	std::cout << "mewww" << std::endl;
}

const Brain* Cat::getIdeas() const {
	return (this->b);
}