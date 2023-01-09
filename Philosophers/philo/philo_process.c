/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:25:20 by staek             #+#    #+#             */
/*   Updated: 2023/01/09 13:49:20 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	take_fork(t_info *info)
{
	if (!pthread_mutex_lock(&info->option->fork[info->rfork]))
	{
		sync_print(info, "has taken a fork", TAKEN);
		if (!pthread_mutex_lock(&info->option->fork[info->lfork]))
			sync_print(info, "has taken a fork", TAKEN);
	}
	else
		return (false);
	return (true);
}

t_bool	put_fork(t_info *info)
{
	info->philo_num_of_eat++;
	if (info->option->number_of_eat == info->philo_num_of_eat)
		info->option->num_of_eat_count_down--;
	if (pthread_mutex_unlock(&info->option->fork[info->rfork]))
		return (false);
	if (pthread_mutex_unlock(&info->option->fork[info->lfork]))
		return (false);
	return (true);
}
