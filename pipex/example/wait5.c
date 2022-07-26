#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	ret;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("child will be exited\n");
	}
	else
	{
		printf("parent pid is %d\n", pid);
		ret = wait(NULL);
		printf("parent retrieved %d\n", ret);
		while (1)
			;
	}
	return (0);
}
