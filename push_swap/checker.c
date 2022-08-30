/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:37:38 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/29 17:39:35 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_operators(const char operators[12][4]
		, char *op, const int len_of_operator)
{
	int	i;

	i = 0;
	while (i < len_of_operator)
	{
		if (ft_strcmp(operators[i], op) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void	operate(t_stack *a, t_stack *b, int *op_list, int i)
{
	if (op_list[i] == 0)
		sab(a, "sa", 0);
	else if (op_list[i] == 1)
		sab(b, "sb", 0);
	else if (op_list[i] == 2)
		ss(a, b, 0);
	else if (op_list[i] == 3)
		pab(b, a, "pa", 0);
	else if (op_list[i] == 4)
		pab(a, b, "pb", 0);
	else if (op_list[i] == 5)
		rab(a, "ra", 0);
	else if (op_list[i] == 6)
		rab(b, "rb", 0);
	else if (op_list[i] == 7)
		rr(a, b, 0);
	else if (op_list[i] == 8)
		rrab(a, "rra", 0);
	else if (op_list[i] == 9)
		rrab(b, "rrb", 0);
	else if (op_list[i] == 10)
		rrr(a, b, 0);
}

void	do_operate(t_stack *a, t_stack *b, int *op_list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		operate(a, b, op_list, i);
		i++;
	}
	if (confirm_ordered(a, 0, a->size -1) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	checker(t_stack *a, t_stack *b)
{
	const char	operators[11][4]
		= {{"sa"}, {"sb"}, {"ss"}, {"pa"},
	{"pb"}, {"ra"}, {"rb"}, {"rr"}, {"rra"}, {"rrb"}, {"rrr"}};
	char		*line;
	int			size;
	int			*op_list;
	int			ret;

	size = 0;
	op_list = (void *)0;
	while (1)
	{
		line = get_next_line(0);
		if (line == 0)
			break ;
		ret = get_operators(operators, ft_strtrim(line, "\n"), 11);
		free(line);
		if (ret == -1)
			pexit();
		size++;
		op_list = append_array_data(op_list, size, ret);
	}
	do_operate(a, b, op_list, size);
	free(op_list);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init(&a, &b, argc, argv);
	checker(&a, &b);
	free((&a)->list);
	free((&b)->list);
	return (0);
}
