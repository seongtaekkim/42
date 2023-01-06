/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:26:31 by staek             #+#    #+#             */
/*   Updated: 2023/01/06 09:43:26 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	sync_print(t_info *info, char *msg, t_status status)
{
	long long	s_time;

	if (pthread_mutex_lock(&info->option->pmutex))
		return (false);
	if (cur_time(&s_time) == false)
		return (false);
	char *a = ft_itoa(s_time - info->option->start_time);
	char *b = ft_itoa(info->id);
	write(STDOUT_FILENO, a, ft_strlen(a));
	write(STDOUT_FILENO, " ", 2);
	write(STDOUT_FILENO, b, ft_strlen(b));
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	write(STDOUT_FILENO, "\n", 1);
	free(a);
	free(b);
	if (status == DIE)
	{
		pthread_mutex_unlock(&info->option->main_mutex);
		return (false);
	}
	if (status == COMPLETED)
	{
		pthread_mutex_unlock(&info->option->main_mutex);
		return (false);
	}
	if (pthread_mutex_unlock(&info->option->pmutex))
		return (false);
	return (true);
}
