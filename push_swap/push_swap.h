/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:12:17 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/22 17:18:39 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

/*
typedef struct s_stack
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}	t_stack;
*/

typedef struct s_stack
{
	int	top;
	int	bottom;
	int	capacity;
	int	size;
	int	*list;
}	t_stack;


void	push(t_stack *s, int data);
void	pop(t_stack *s);
int		peek(t_stack *s);
void	sab(t_stack *s, char *op);
//void	ss(t_stack *a, t_stack *b);
void	pab(t_stack *a, t_stack *b, char *op);
void	rab(t_stack *s, char *op);
void	rr(t_stack *a, t_stack *b);
void	rrab(t_stack *s, char *op);
void	rrr(t_stack *a, t_stack *b);
void	swap_a(t_stack *a, t_stack *b, int l, int r);
void	swap_b(t_stack *a, t_stack *b, int l, int r);

int		pexit();
int		confirm_ordered_desc(t_stack *a, int l, int r);
int		confirm_ordered(t_stack *a, int l, int r);
void	ft_sort_int_tab(int *tab, int size);
int		*get_pivot(t_stack *a, int l, int r);
int		search_dupl(t_stack *s, int target);
void	init(t_stack *a, t_stack *b, int num, char **data);
void	output(char *s);

int    process1(t_stack *a, t_stack *b, int l, int r);
int    process2(t_stack *a, t_stack *b, int l, int r);

char	*get_next_line(int fd);
#endif
