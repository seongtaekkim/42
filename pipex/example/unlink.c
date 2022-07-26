#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!access(argv[i], F_OK))
		{
			if (!unlink(argv[i]))
				printf("file is unlinked\n");
			else
				printf("file is not unlinked\n");
		}
		else
			printf("file is not existing\n");
	}
	return (0);
}
