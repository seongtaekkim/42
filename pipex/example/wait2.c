#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void print(int sig)
{
	printf("child signal : %d\n", sig);
}

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
		signal(SIGCONT, print);
		printf("child will be stopped\n");
		while (1)
			;
	}
	else
	{
		printf("parent : i hava a child with pid %d\n", pid);
		ret = waitpid(pid, &status, WUNTRACED);
		printf("parent : child has been sttopped\n");
		printf("parent : child's exit status : %d\n", ret);
		if (WIFSTOPPED(status))
			printf("parent : exit code is %d, signal is %d\n",WSTOPSIG(status), WTERMSIG(status));
		usleep(10000000);
		ret = waitpid(pid, &status, WCONTINUED | WNOHANG);
		printf("parent : child has been continued\n");
		printf("parent : child's sattus is %d\n", ret);
		if (WIFCONTINUED(status))
			printf("parent : exit code is %d, signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
	}
	return (0);
}
