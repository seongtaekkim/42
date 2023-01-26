#include "Base.hpp"

int main(void) {
	for (int i = 0; i < 5; ++i)
	{
		Base* base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	return (0);
}