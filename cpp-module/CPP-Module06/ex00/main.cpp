#include "Cast.hpp"
#include <iostream>
#include <iomanip>
#include <cmath> // isnan, isinf
#include <cstdlib>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

int main(int argc, char **argv) {

	if (argc != 2)
		std::cout << "Invalid input" << std::endl
			<< "Usage: ./convert [Argument to convert]" << std::endl;
	else
		Cast(std::string(argv[1]));
	return (0);
}

/*
** char: 'c'(99), 'a'(97)
** int: 0, -42, 42
** float: 0.0f, -4.2f, 4.2f, -inff, +inff and nanf
** double: 0.0, -4.2, 4.2, -inf, +inf and nan
*/