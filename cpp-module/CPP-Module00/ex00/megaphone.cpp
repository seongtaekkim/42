#include <iostream>

void toupperMessage(int &count, char **messages) {
	int		index;
	size_t	jndex;

	index = 1;
	while (index < count)
	{
		jndex = 0;
		while (messages[index][jndex])
		{
			std::cout << char(std::toupper(messages[index][jndex]));
			jndex++;
		}
		index++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		toupperMessage(argc, argv);
	return (0);
}