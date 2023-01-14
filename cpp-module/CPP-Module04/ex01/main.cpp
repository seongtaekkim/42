
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

	Cat origin;
	{
		Cat copy(origin);
		copy = origin;
		std::cout << origin.getIdeas()[0] << std::endl; 
	}
	std::cout << origin.getIdeas()[0] << std::endl; 
	std::cout << "=======================" << std::endl;
	Dog origin2;
	{
		Dog copy(origin2);
		copy = origin2;
		std::cout << origin2.getIdeas()[0] << std::endl; 
	}
	std::cout << origin2.getIdeas()[0] << std::endl; 
	system("leaks animal");
	return 0;

}