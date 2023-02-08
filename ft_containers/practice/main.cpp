
#include <iostream>
#include <vector>

class A {
public:
  typedef size_t size_type;
};

int main() {
	std::cout << A::size_type(-1)   << std::endl;
	return 0;
}