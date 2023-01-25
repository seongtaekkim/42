
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const Animal *animal[100];
	for (int i = 0 ; i < 100 ; i++) {
		if (i < 50)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	for (int i = 0 ; i< 100 ; i++)
		delete animal[i];
	std::cout << "=======================" << std::endl;
	Cat origin;
	std::cout << "=======================" << std::endl;
	{
		Cat copy(origin);
		std::cout << "=======================" << std::endl;
		copy = origin;
		std::cout << *origin.getIdeas() << std::endl; 
	}
	std::cout << *origin.getIdeas() << std::endl; 
	std::cout << "=======================" << std::endl;
	return 0;
}