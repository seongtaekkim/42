#include "Bureaucrat.hpp"

void testcase2(void) {
	Bureaucrat seongtki("seongtki", 1);
	Bureaucrat staek("staek", 150);

	std::cout << seongtki << std::endl;
	std::cout << staek << std::endl;
	try {
		staek.decrement();
		std::cout << staek << std::endl;
		staek.increment();
		staek.increment();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		seongtki.increment();
		std::cout << seongtki << std::endl;
		seongtki.decrement();
		seongtki.decrement();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void testcase1(void) {
	try {
		Bureaucrat s("seongtki", 0);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat m("staek", 151);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(void) {
	testcase1();
	testcase2();
	return (0);
}
