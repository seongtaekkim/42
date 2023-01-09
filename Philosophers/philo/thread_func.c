/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:15:01 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/09 14:03:54 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func_eating_t(void *data)
{
	t_info	*info;

	info = (t_info *)data;
	if (info->id % 2 == 0)
		if (wait_time(50) == false)
			pthread_mutex_unlock(&info->option->main_mutex);
	while (1)	
	{
		if (!take_fork(info))
			pthread_mutex_unlock(&info->option->main_mutex);
		sync_print(info, "is eating", EATING);
		if (cur_time(&(info->philo_time)) == false)
			pthread_mutex_unlock(&info->option->main_mutex);
		if (wait_time(info->option->time_to_eat) == false)
			pthread_mutex_unlock(&info->option->main_mutex);
		if (!put_fork(info))
			pthread_mutex_unlock(&info->option->main_mutex);
		sync_print(info, "is sleeping", SLEEP);
		if (wait_time(info->option->time_to_sleep) == false)
			pthread_mutex_unlock(&info->option->main_mutex);
		sync_print(info, "is thinking", THINK);
	}
	return (0);
}

static int	check_finish(long long s_time, t_info info)
{
	if (s_time > (info.philo_time + (long long)info.option->time_to_die))
	{
		sync_print(&info, "is died", DIE);
		return (0);
	}
	if (info.option->num_of_eat_count_down == 0)
	{
		sync_print(&info, "All philo completed", COMPLETED);
		return (0);
	}
	return (1);
}

void	*func_monitor_t(void *data)
{
	t_info		*info;
	long long	s_time;
	int			i;

	info = (t_info *)data;
	while (1)
	{
		i = 0;
		while (i < info[0].option->number_of_philo)
		{
			if (cur_time(&s_time) == false)
				pthread_mutex_unlock(&info->option->main_mutex);
			if (check_finish(s_time, info[i]) == 0)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
