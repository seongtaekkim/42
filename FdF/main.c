#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


void	print(int fd)
{
	char	*line;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		//printf("%s", line);
		free(line);
		if (!line)
			break ;
	}
}
int st_read_map(const char *filename)
{
    int fd;
    int i;
	char	*line;

    i = -1;
    fd = open(filename, O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		if (line == 0)
		{
			break ;
		}
		printf("%s", line);
		free(line);
		break ;
		if (!line)
			break ;
	}
	/*while (1)
	{
	}*/
    return (fd);
}
#include <unistd.h>
#include <fcntl.h>

void	test(int fd)
{
	char	*buf = (char *)malloc(sizeof(char)*42);
	ssize_t  n;
	n = read(fd,buf, 5);
	///c = 1;
	printf("local n : %lu, %s*\n",n, buf);	
	free(buf);
	if(n <= 0)
		return;
}

int main(int argc, char **argv)
{
	int		index;
	/*(void) argc;
	(void) argv;
	char str[100] = "hello\0\0\0byebye\0\0good\0\0";
	int fd;

	fd = open("test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	write(fd, str, 100);
    close(fd);
*/
	index = 1;
 if (argc == 1)
	{
		print(0);
	}
	else
    {
		while (argc > index)
        	st_read_map(argv[index++]);
    }

	(void)argc;
	(void)argv;
	/*	char *name = "lines_around_10.txt";
		int fd_1 = open(name, O_RDONLY);
		int fd_2 = open(name, O_RDONLY);
		printf("%s",get_next_line(fd_1));
		 printf("%s",get_next_line(fd_2));
		 printf("%s",get_next_line(fd_1));
		 printf("%s",get_next_line(fd_2));
		 printf("%s",get_next_line(fd_2));
		 printf("%s",get_next_line(fd_2));
		 printf("%s",get_next_line(fd_2));
		 printf("%s",get_next_line(fd_2));
		 printf("%s",get_next_line(fd_1));
		 printf("%s",get_next_line(fd_1));
		 printf("%s",get_next_line(fd_1));
		 printf("%s",get_next_line(fd_1));
    */
/*	
char *name = "lines_around_10.txt";
		int fd_1 = open(name, O_RDONLY);
		int fd_2 = open(name, O_RDONLY);
		int fd_3 = open(name, O_RDONLY);

		 printf("1: %s",get_next_line(fd_1));
		 printf("2: %s",get_next_line(fd_2));
		 printf("3: %s",get_next_line(fd_3));
		 printf("1: %s",get_next_line(fd_1));
		 printf("2: %s",get_next_line(fd_2));
		 printf("2: %s",get_next_line(fd_2));


//int fd_4 = open("giant_line_nl.txt", O_RDONLY);
int fd_4 = open("42_with_nl", O_RDONLY);

		printf("2: %s",get_next_line(fd_2));
		 printf("3: %s",get_next_line(fd_3));
		 printf("4: %s",get_next_line(fd_4));
		 printf("2: %s",get_next_line(fd_2));
		 printf("2: %s",get_next_line(fd_2));
		 printf("1: %s",get_next_line(fd_1));
		 printf("4: %s",get_next_line(fd_4));
		 printf("1: %s",get_next_line(fd_1));
		 printf("4: %s",get_next_line(fd_4));
		 printf("1: %s",get_next_line(fd_1));
		 printf("4: %s",get_next_line(fd_4));
		 printf("3: %s",get_next_line(fd_3));
		 printf("3: %s",get_next_line(fd_3));
		 printf("1: %s",get_next_line(fd_1));
		 printf("3: %s",get_next_line(fd_3));
		 printf("3: %s",get_next_line(fd_3));
*/		

/*
int fd_1 = open("42_with_nl2", O_RDONLY);
	char	*buf = (char *)malloc(sizeof(char)*42);
	//char c = 0; 
	printf("$%s$",get_next_line(fd_1));
	ssize_t  n;
	n = read(fd_1,buf, 42);
	///c = 1;
	printf("n : %lu, %s*\n",n, buf);	
	free(buf);
	printf("$%s$",get_next_line(fd_1));
	buf = (char *)malloc(sizeof(char)*42);
	n = read(fd_1,buf, 5);
	
	printf("n : %lu, %s*\n",n, buf);	
	free(buf);
	test(fd_1);
	test(fd_1);
	test(fd_1);
	printf("$%s$",get_next_line(fd_1));
	if (get_next_line(fd_1) != NULL)
		printf("not null");
*/	
	return (0);
}
