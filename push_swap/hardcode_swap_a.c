#include "push_swap.h"



static int	hard_size2_a(t_stack *a, t_swapinfo info)
{
    if (info.size == 2 && a->top == info.r)
	{
		if (a->list[info.r] > a->list[info.l])
			sab(a, "sa", 1);
		return (1);
	}
	return (0);
}

static void	hard_capacity3_a(t_stack *a, t_swapinfo info)
{
	if (a->list[info.r] > a->list[info.l + 1])
	{
		if (a->list[info.l + 1] > a->list[info.l]) // 3 2 1
		{	
			rab(a, "ra", 1);
			sab(a, "sa", 1);
		}
		else if (a->list[info.l] > a->list[info.r])
			sab(a, "sa", 1);
		else // 3 1 2
			rab(a, "ra", 1);
	}
	else
	{
		if (a->list[info.r] > a->list[info.l]) // 2 3 1
			rrab(a, "rra", 1);
		else if (a->list[info.r] < a->list[info.l] && a->list[info.l] < a->list[info.l + 1]) // 1 3 2
		{
			rrab(a, "rra", 1);
			sab(a, "sa", 1);
		}
	}
}

static void	hard_size3_a1(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (a->list[info.l + 1] > a->list[info.l]) // 3 2 1
	{
		sab(a, "sa", 1);
		pab(a, b, "pb", 1);
		sab(a, "sa", 1);
		pab(b, a, "pa", 1);
		sab(a, "sa", 1);
	}
	else if (a->list[info.l] > a->list[info.r])
		sab(a, "sa", 1);
	else // 3 1 2
	{
		sab(a, "sa", 1);
		pab(a, b, "pb", 1);
		sab(a, "sa", 1);
		pab(b, a, "pa", 1);
	}
}

static void	hard_size3_a2(t_stack *a, t_stack *b, t_swapinfo info)
{
	if (a->list[info.r] > a->list[info.l])  // 2 3 1
	{
		pab(a, b, "pb", 1);
		sab(a, "sa", 1);
		pab(b, a, "pa", 1);
		sab(a, "sa", 1);
	}
	else if (a->list[info.r] < a->list[info.l] && a->list[info.l] < a->list[info.l + 1])// 1 3 2
	{
		pab(a, b, "pb", 1);
		sab(a, "sa", 1);
		pab(b, a, "pa", 1);
	}
}

int    do_hardcode_a(t_stack *a, t_stack *b,  t_swapinfo info)
{
	if (hard_size2_a(a, info))
		return (1);
    if (a->capacity == 3)
	{
		hard_capacity3_a(a, info);
		return (1);
	}
    if (info.size == 3 && a->top == info.r)
	{
		if (a->list[info.r] > a->list[info.l + 1])
			hard_size3_a1(a, b, info);
		else
			hard_size3_a2(a, b, info);
		return (1);
	}
    return (0);
}