#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	ret;
	int		status;

	status = 1000;
	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("child start\n");
		return (44);
	}
	else
	{
		printf("parent : pid : %d\n", pid);
		ret = wait(&status);
		printf("parent: child's status is : %d\n", ret);
		if (WIFEXITED(status))
			printf("parent : exit code is %d, signal is %d, status : %d\n"
					, WEXITSTATUS(status), WTERMSIG(status), status >> 8);
		// status는int(4byte)인데, index=2 : 종료코드, index=3 : 시그널 코드이다. 
		// status : 정상종료한 경우 signal 값이0이므로 오른쪽으로 8비트만큼 이동시키면 종료코드를 정확히 취득한 것임.
	}
	return (0);
}
