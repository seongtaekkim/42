#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("current error: %s\n", strerror(errno + 2));
	return (0);
}
