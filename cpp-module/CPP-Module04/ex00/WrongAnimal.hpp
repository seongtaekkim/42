#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &animal);
    virtual ~WrongAnimal();
    WrongAnimal &operator = (const WrongAnimal &f);
	void makeSound() const;
	std::string getType() const;
};

#endif