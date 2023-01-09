/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:26:31 by staek             #+#    #+#             */
/*   Updated: 2023/01/09 13:49:30 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

int	check_status(t_status status, t_info *info)
{
	if (status == DIE)
	{
		pthread_mutex_unlock(&info->option->main_mutex);
		return (0);
	}
	if (status == COMPLETED)
	{
		pthread_mutex_unlock(&info->option->main_mutex);
		return (0);
	}
	return (1);
}

t_bool	sync_print(t_info *info, char *msg, t_status status)
{
	long long	s_time;
	char		*start_time;
	char		*philo_id;

	if (pthread_mutex_lock(&info->option->pmutex))
		return (false);
	if (cur_time(&s_time) == false)
		return (false);
	start_time = ft_itoa(s_time - info->option->start_time);
	philo_id = ft_itoa(info->id);
	write(STDOUT_FILENO, start_time, ft_strlen(start_time));
	write(STDOUT_FILENO, " ", 2);
	write(STDOUT_FILENO, philo_id, ft_strlen(philo_id));
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	write(STDOUT_FILENO, "\n", 1);
	free(start_time);
	free(philo_id);
	if (check_status(status, info) == 0)
		return (false);
	if (pthread_mutex_unlock(&info->option->pmutex))
		return (false);
	return (true);
}
