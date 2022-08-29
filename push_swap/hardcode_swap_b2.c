#include "push_swap.h"

int	hard_size2_b(t_stack *a, t_stack *b, t_swapinfo info)
{
    if (info.size == 2 && b->top == info.r)
	{
		if (b->list[info.r] > b->list[info.l])
		{
			pab(b, a, "pa", 1);
			pab(b, a, "pa", 1);
			return (1);
		}
		else
		{
			sab(b, "sb", 1);
			pab(b, a, "pa", 1);
			pab(b, a, "pa", 1);
			return (1);
		}
	}
	return (0);
}