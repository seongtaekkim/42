#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
	Dog(const Dog &dog);
    ~Dog();
    Dog &operator = (const Dog &f);
	virtual void makeSound() const;
};

#endif