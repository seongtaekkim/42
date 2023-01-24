#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &f) {
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = f;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &f) {
    std::cout << "WrongCat Copy Assignment operator called" << std::endl;
    if (this == &f)
        return (*this);
    return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "wrong mewww" << std::endl;
}