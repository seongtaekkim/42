/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:15:30 by susong            #+#    #+#             */
/*   Updated: 2023/01/03 13:21:59 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

// n_flag가 맞으면 1, 아니면 0
int	n_flag_check(char *flag_string)
{
	int	index;

	index = 2;
	while (flag_string[index])
	{
		if (flag_string[index] != 'n')
			return (0);
		index++;
	}
	return (1);
}

// write로 string 출력해준다. n_flag유무에 따라 n 옵션 있을 시, 마지막에 \n안함 Good : 0 BAD : not 0
void	ft_echo(char **string, int *exit_code)
{
	int	index;
	int	n_flag;

	n_flag = 0;
	index = 0;
	if (!string[0])
	{
		s_write(1, "\n");
		return ;
	}
	else if (string[0][0] == '-' && string[0][1] == 'n')
		n_flag = n_flag_check(string[0]);
	if (n_flag)
		index += 1;
	while (string[index])
	{
		s_write(1, string[index]);
		if (string[index + 1])
			s_write(1, " ");
		index++;
	}
	if (n_flag == 0)
		s_write(1, "\n");
	(*exit_code) = 0;
	return ;
}

void	ft_echo_exit(char **string, int *exit_code)
{
	int	index;
	int	n_flag;

	n_flag = 0;
	index = 0;
	if (!string[0])
	{
		s_write(1, "\n");
		exit (1);
	}
	else if (string[0][0] == '-' && string[0][1] == 'n')
		n_flag = n_flag_check(string[0]);
	if (n_flag)
		index += 1;
	while (string[index])
	{
		s_write(1, string[index]);
		if (string[index + 1])
			s_write(1, " ");
		index++;
	}
	if (n_flag == 0)
		s_write(1, "\n");
	(*exit_code) = 0;
	exit(0);
}
