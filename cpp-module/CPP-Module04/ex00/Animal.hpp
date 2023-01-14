#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
protected:
	std::string type;
public:
    Animal();
    Animal(const Animal &animal);
    virtual ~Animal();
    Animal &operator = (const Animal &f);
	virtual void makeSound() const;
	std::string getType() const;
};

#endif