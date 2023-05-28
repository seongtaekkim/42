#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    
	if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " [positive integer sequence]" << std::endl;
        return (1);
    }

    char* err = NULL;
    for (int i = 1; i < argc; ++i) {
        long longdata = std::strtol(argv[i], &err, 10);
        if (*err || longdata <= 0 || longdata > std::numeric_limits<int>::max()) {
            std::cout << "Error" << std::endl;
            return (1);
        }
    }

    try {
        PmergeMe merge(argc, argv);
		merge.show();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return 0;
}