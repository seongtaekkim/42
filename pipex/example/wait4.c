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
		printf("child start\n");
		usleep(10000000);
		return (3);
	}
	else
	{
		printf("parent : pid : %d\n", pid);
		ret = waitpid(pid, &status, WUNTRACED | WCONTINUED);
		printf("parent : child's status : %d, bit : %d\n", status, status >> 8);
		if (WIFEXITED(status))
			printf("parent : exited, exit code is %d, signal is %d\n",WEXITSTATUS(status), WTERMSIG(status));
		else if(WIFSIGNALED(status))
			printf("parent : signaled, exit code is $d, signal is %d\n",WEXITSTATUS(status), WTERMSIG(status));
		else if (WIFSTOPPED(status))
			printf("parent : stopped, exit code is %d, signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
		else if (WIFCONTINUED(status))
			printf("parent : continued, exit code is %d, signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
	}
	return (0);
}
