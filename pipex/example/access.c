#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	mode;

	printf("fok : %d, xok : %d\n", F_OK, X_OK);
	mode = 0;
	mode |= F_OK;
	printf("mode : %d\n", mode);
	if (!access("test.txt", mode))
		printf("File is existing\n");
	else
		printf("File is not existing\n");
	//mode &= 0;
	mode |= X_OK;
	printf("mode : %d\n", mode);
	if (!access("test.txt", mode))
		printf("File is executable\n");
	else
		printf("File is not executable\n");
	return (0);
}
