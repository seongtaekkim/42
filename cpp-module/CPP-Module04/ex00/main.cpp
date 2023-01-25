
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main() {
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << *j << " " << std::endl;
		std::cout << *i << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete j;
		delete i;
		delete meta;
	}
	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << *i << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete i;
		delete meta;
	}
	return 0;
}