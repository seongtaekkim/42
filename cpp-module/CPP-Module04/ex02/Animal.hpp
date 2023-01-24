#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string type;
    Animal();
    Animal(const Animal& animal);
public:
    virtual ~Animal();
	Animal& operator = (const Animal& a);
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif