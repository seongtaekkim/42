#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		//usleep(1000000);
		printf("child pid : %d\n", pid);
		usleep(100000);
		printf("child end\n");
	}
	else if (pid)
	{
		printf("parent pid : %d\n", pid);
		usleep(1000000);
		printf("parent end\n");
	}
	return (0);
}
