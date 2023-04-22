#include "PmergeMe.hpp"


int main(int argc, char *argv[]) {
    
	// validate num of argument
	if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [positive integer sequence]" << std::endl;
        return (1);
    }

	// validate disit in argument
    char* err = NULL;
    for (int i = 1; i < argc; ++i) {
        long toLong = std::strtol(argv[i], &err, 10);
        if (*err || toLong <= 0 || toLong > std::numeric_limits<int>::max()) {
            std::cerr << "Error" << std::endl;
            return (1);
        }
    }

	// do merge
    try {
        PmergeMe merge(argc, argv);
		merge.show();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return 0;
}