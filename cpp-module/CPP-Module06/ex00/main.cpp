#include "Cast.hpp"

int main(int argc, char **argv) {

	if (argc != 2)
		std::cout << "Invalid num of input" << std::endl;
	else
		Cast(std::string(argv[1]));
	return (0);
}