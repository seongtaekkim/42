/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:15:33 by susong            #+#    #+#             */
/*   Updated: 2023/01/03 13:58:45 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_bonus.h"

int	is_numeric(char **argument)
{
	int	index;

	index = 0;
	while (argument[0][index])
	{
		if (!('0' <= argument[0][index] \
			&& argument[0][index] <= '9'))
			return (0);
		index++;
	}
	return (1);
}

void	ft_exit(char **argument, int *exit_code)
{
	int	index;

	index = 0;
	while (argument[index])
		index++;
	s_write(1, "exit\n");
	if (index == 0)
		exit (0);
	else if (is_numeric(argument) == 0)
	{
		s_write(2, "shell: exit: ");
		s_write(2, argument[0]);
		s_writeln(2, ": 숫자 인자가 필요함");
		(*exit_code) = 2;
		exit(2);
	}
	else if (index > 1)
	{
		s_writeln(2, "shell: exit: 인자가 너무 많음");
		(*exit_code) = 1;
		return ;
	}
	(*exit_code) = 0;
	exit(ft_atoi(argument[0]) % 256);
}

void	ft_exit_exit(char **argument, int *exit_code)
{
	int	index;

	index = 0;
	while (argument[index])
		index++;
	if (index == 0)
		exit (0);
	else if (is_numeric(argument) == 0)
	{
		s_write(2, "shell: exit: ");
		s_write(2, argument[0]);
		s_writeln(2, ": 숫자 인자가 필요함");
		(*exit_code) = 2;
		exit(2);
	}
	else if (index > 1)
	{
		s_writeln(2, "shell: exit: 인자가 너무 많음");
		(*exit_code) = 1;
		exit(1);
	}
	(*exit_code) = 0;
	exit(ft_atoi(argument[0]) % 256);
}
