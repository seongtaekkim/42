#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * l : list, v : vector, e : environment, p: path
 * execve : v (vector), e (environment)
 * e 가변인자에는 마지막에 null을 넣어 구분할 수 있게 해주어야 한다. 
 */
int	main(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 1)
		return (1);
	i = -1;
	args = (char **)malloc(argc * sizeof(char *));
	if (!args)
		return (1);
	args[argc - 1] = NULL;
	while (++i < argc - 1)
		args[i] = argv[i + 1];
	
	// access로 실행권한있는지 체크가 필요함
	execve("/usr/bin/gcc", args, NULL);
	free(args);
	return (0);
}
