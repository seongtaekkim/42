#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << REDCOLOR <<  "Error: could not open file." << ENDCOLOR << std::endl;
        return (1);
    }

	try {
        File file(argv[1]);
        file.readFile(File::SEPARATOR_PIPE);
	}
	catch(const std::exception& e) {
		std::cout << REDCOLOR << e.what() << ENDCOLOR << std::endl;
	}

    return (0);
}