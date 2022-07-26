#include <stdio.h>
#include <errno.h>

int main(void)
{
	//printf("current errno: %d\n", errno);
	//printf("current sys_nerr: %d\n", sys_nerr);
	perror(NULL);
	return (0);
}
