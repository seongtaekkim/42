#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *b;
public:
    Cat();
	Cat(const Cat& cat);
    virtual ~Cat();
    Cat& operator = (const Cat& c);
	virtual void makeSound() const;
	const std::string *getIdeas() const;
};

#endif