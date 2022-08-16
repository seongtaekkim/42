/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:12:17 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/16 14:41:21 by seongtki         ###   ########.fr       */
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
	int	size;
	int	*list;
}	t_stack;

int	pexit();
void	push(t_stack *s, int data);
void	pop(t_stack *s);
int		peek(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *a, t_stack *b);
#endif
