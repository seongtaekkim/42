#include "Base.hpp"

Base::Base(void) {}
Base::~Base(void) {}

Base* generate(void) {
	struct timeval t;
	gettimeofday(&t, NULL);
	srand(t.tv_usec);
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Instanciated A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Instanciated B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Instanciated C" << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

A::~A(void) {}
B::~B(void) {}
C::~C(void) {}

void identify(Base* p) {
	if (p == NULL)
		std::cerr << "this instance has none." << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cerr << "this instance hasn't A,B,C" << std::endl;
}

static bool checkIdentifyRef(Base& p, std::string type) {
	try {
		if (type == "A")
			static_cast<void>(dynamic_cast<A&>(p));
		if (type == "B")
			static_cast<void>(dynamic_cast<B&>(p));
		if (type == "C")
			static_cast<void>(dynamic_cast<C&>(p));
		std::cout << type << std::endl;
		return (true);
	} catch (std::bad_cast& e) {
		std::cerr << "bad_cast exception !" << std::endl;
		return (false);
 	}
}

void identify(Base& p) {
	if (!checkIdentifyRef(p, "A") && !checkIdentifyRef(p, "B") && !checkIdentifyRef(p, "C"))
		std::cerr << "not found concrete instance" << std::endl;
}