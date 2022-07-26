#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global;

int	main(void)
{
	int		automatic;
	int		*heap;
	pid_t	pid;
	
	global = 10;
	automatic = 10;
	heap = (int *)malloc(sizeof(int));
	
	*heap = 10;
	pid = fork();
	if (pid == -1)
	{
		free(heap);
		return (1);
	}
	else if (!pid)
	{
		printf("child : before : global : %d, automatic : %d, heap : %d\n", global, automatic, *heap);
		global += 1;
		automatic += 1;
		*heap += 1;
		printf("child : after : global : %d, automatic : %d, heap : %d\n", global, automatic, *heap);
	}
	else if(pid)
	{
		printf("parent : before : global : %d, automatic : %d, heap : %d\n", global, automatic, *heap);
		global += 100;
		automatic += 100;
		*heap += 100;
		printf("parent : after : global : %d, automatic : %d, heap : %d\n", global, automatic, *heap);
	}
	free(heap);
	return (0);
}
