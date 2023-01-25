#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string type;
public:
    Animal();
    Animal(const Animal &animal);
    virtual ~Animal();
    Animal& operator = (const Animal& a);
	virtual void makeSound() const;
	std::string getType() const;
};

std::ostream& operator<< (std::ostream& out, const Animal& a);

#endif