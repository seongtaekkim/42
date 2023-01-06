/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:31:26 by staek             #+#    #+#             */
/*   Updated: 2023/01/06 02:03:00 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_mutex(t_info *info)
{
	int	index;

	index = 0;
	if (info)
	{
		while (info->option->number_of_philo > index)
		{
			pthread_mutex_destroy(&info->option->fork[index]);
			index++;
		}
	}
	pthread_mutex_destroy(&info->option->pmutex);
	pthread_mutex_destroy(&info->option->main_mutex);
}

int	exit_process(t_info *info)
{
	if (info)
		free_mutex(info);
	usleep(1000000);
	return (0);
}