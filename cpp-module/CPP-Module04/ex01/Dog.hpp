#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *b;
public:
    Dog();
	Dog(const Dog& dog);
    virtual ~Dog();
    Dog& operator = (const Dog& d);
	virtual void makeSound() const;
	const Brain* getIdeas() const;
};

#endif