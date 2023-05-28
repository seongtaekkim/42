#include "RPN.hpp"

int	main(int ac, char **av) {
	try {
        RPN rpn;
		rpn.check(ac, av[1], 0);
		rpn.run(av[1], 0);
	} catch(const std::exception& e) {
		std::cout << REDCOLOR << e.what() << ENDCOLOR << std::endl;
	}
	return 0;
}