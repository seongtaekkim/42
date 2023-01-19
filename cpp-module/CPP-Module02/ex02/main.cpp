#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;	// 0
	std::cout << ++a << std::endl;	// 0.00390625
	std::cout << a << std::endl;	// 0.00390625
	std::cout << a++ << std::endl;	// 0.00390625
	std::cout << a << std::endl;	// 0.0078125
	std::cout << b << std::endl;	// 10.1016
	std::cout << Fixed::fmax(a, b);	// 10.1016
	std::cout << std::endl;
	std::cout << Fixed::fmin(a, b);	// 0.0078125
	std::cout << std::endl;
	return (0);
}