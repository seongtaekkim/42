#include <iostream>
#include "../stack.hpp"

int main(void) {
	ft::stack<int> s1, s2;
	s1.push(1);
	s1.push(2);
	s2.push(1);

	std::cout << (s1 == s2) << std::endl;
	return (0);
}