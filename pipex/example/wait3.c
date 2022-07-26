#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	ret;
	int		status;
	
	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("child will get signal\n");
		while (1)
			;
	}
	else
	{
		printf("parent have pid %d\n", pid);
		ret = wait(&status);
		printf("parent get status %d\n", ret);
		if (WIFSIGNALED(status))
			printf("parent : exit code is %d, signal is %d",WEXITSTATUS(status), WTERMSIG(status));
	}
	return (0);
}
