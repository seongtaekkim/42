#include "push_swap.h"


int    process1(t_stack *a, t_stack *b, int l, int r)
{
    int size;

    size = r - l + 1;
    if (size == 2 && a->top == r)
	{
		if (a->list[r] > a->list[l])
			sab(a, "sa");
		return (1);
	}

    if (a->capacity == 3)
	{
		if (a->list[r] > a->list[l + 1])
		{
			if (a->list[l + 1] > a->list[l]) // 3 2 1
			{	
                rab(a, "ra");
				sab(a, "sa");
			}
			else if (a->list[l] > a->list[r])
				sab(a, "sa");
			else // 3 1 2
                rab(a, "ra");
		}
		else
		{
			if (a->list[r] > a->list[l]) // 2 3 1
                rrab(a, "rra");
			else if (a->list[r] < a->list[l] && a->list[l] < a->list[l + 1]) // 1 3 2
			{
                rrab(a, "rra");
                sab(a, "sa");
			}
		}
		return (1);
	}

    if (size == 3 && a->top == r)
	{
		if (a->list[r] > a->list[l + 1])
		{
			if (a->list[l + 1] > a->list[l]) // 3 2 1
			{
				sab(a, "sa");
				pab(a, b, "pb");
				sab(a, "sa");
				pab(b, a, "pa");
				sab(a, "sa");
			}
			else if (a->list[l] > a->list[r])
				sab(a, "sa");
			else // 3 1 2
			{
				sab(a, "sa");
				pab(a, b, "pb");
				sab(a, "sa");
				pab(b, a, "pa");
			}
		}
		else
		{
			if (a->list[r] > a->list[l])  // 2 3 1
			{
				pab(a, b, "pb");
				sab(a, "sa");
				pab(b, a, "pa");
				sab(a, "sa");
			}
			else if (a->list[r] < a->list[l] && a->list[l] < a->list[l + 1])// 1 3 2
			{
				pab(a, b, "pb");
				sab(a, "sa");
				pab(b, a, "pa");
			}
		}
		return (1);
	}
    return (0);
}

int    process2(t_stack *a, t_stack *b, int l, int r)
{
	int size;

    size = r - l + 1;
    if (size == 2 && b->top == r)
	{
		if (b->list[r] > b->list[l])
		{
			pab(b, a, "pa");
			pab(b, a, "pa");
			return (1);
		}
		else
		{
			sab(b, "sb");
			pab(b, a, "pa");
			pab(b, a, "pa");
			return (1);
		}
	}
	if (size == 3 && b->top == r && l == 0)
	{
		if (b->list[r] > b->list[l + 1])
		{
			if (b->list[l + 1] > b->list[l])
			{	
				// 3 2 1
				pab(b, a, "pa");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else if (b->list[l] > b->list[r])
			{
				// 2 1 3
				rrab(b, "rrb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else
			{
				// 3 1 2
				pab(b, a, "pa");
				sab(b, "sb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
				
			}
		}
		else
		{
			if (b->list[r] > b->list[l])
			{
				// 2 3 1
				sab(b, "sb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else if (b->list[l] > b->list[l + 1])
			{
				// 1 2 3
				rrab(b, "rrb");
				pab(b, a, "pa");
				sab(b, "sb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else
			{	// 1 3 2
				sab(b, "sb");
				pab(b, a, "pa");
				sab(b, "sb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
		}
	}
	else if (size == 3 && b->top == r)
	{
		if (b->list[r] > b->list[l + 1])
		{
			if (b->list[l + 1] > b->list[l])
			{	
				// 3 2 1
				pab(b, a, "pa");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else if (b->list[l] > b->list[r])
			{
				// 2 1 3
				rab(b, "rb");
				sab(b, "sb");
				pab(b, a, "pa");
				rrab(b, "rrb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else
			{
				// 3 1 2
				pab(b, a, "pa");
				sab(b, "sb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
				
			}
		}
		else
		{
			if (b->list[r] > b->list[l])
			{
				// 2 3 1
				sab(b, "sb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else if (b->list[l] > b->list[l + 1])
			{
				// 1 2 3
				sab(b, "sb");
				rab(b, "rb");
				sab(b, "sb");
				pab(b, a, "pa");
				rrab(b, "rrb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
			else
			{	// 1 3 2
				sab(b, "sb");
				pab(b, a, "pa");
				sab(b, "sb");
				pab(b, a, "pa");
				pab(b, a, "pa");
				return (1);
			}
		}
	}
    return (0);
}