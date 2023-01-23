#include "Replace.hpp"
#include <cstring>

int main(int argc, char *argv[])
{

    if (argc != 4) {
		std::cout << "argument must have three" << std::endl;
        return (0);
	}
	Replace r(argv[1], argv[2], argv[3]);
	r.replace();
	if (errno) {
		std::cerr << std::strerror(errno) << std::endl;
		return (errno);
	}
    return (0); 
}