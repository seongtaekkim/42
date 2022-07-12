#include "get_next_line.h"
#include <stdio.h>

t_holder   *make_lst(t_holder *head, int fd, char *test)
{
    t_holder   *node;

    node = head->next;
    while (node)
    {
        if (node->fd == fd)
            return (node);
        node = node->next;
    }
	
    node = (t_holder *)malloc(sizeof(t_holder));
    if (!node)
        return (NULL);
    node->fd = fd;
    node->line = ft_strndup(test, 10);
	node->next = head->next;
    node->prev = head;
    head->next = node;
    return (node);
}

void	ddo(int index, char *test)
{
	static t_holder head;
	t_holder *node = make_lst(&head, index, test);
	
	while (node)
	{
		printf("%s\n", node->line);
		node = node->next;
	}

}


#include <stdlib.h>
int	main(void)
{
	int index=0;

	while (index < 5)
	{

		char *test =  "aaa";
		ddo(index, test);
		index++;
		printf("\n\n");
	}

}
