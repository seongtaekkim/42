#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
	WrongCat(const WrongCat &cat);
    ~WrongCat();
    WrongCat& operator = (const WrongCat &f);
	void makeSound() const;
};

#endif