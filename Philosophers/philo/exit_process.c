/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:31:26 by staek             #+#    #+#             */
/*   Updated: 2023/01/09 14:06:45 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

int	free_mutex(t_option *option)
{
	int	index;

	index = 0;
	if (option)
	{
		while (option->number_of_philo > index)
		{
			pthread_mutex_destroy(&option->fork[index]);
			index++;
		}
	}
	pthread_mutex_destroy(&option->pmutex);
	pthread_mutex_destroy(&option->main_mutex);
	return (0);
}

int	exit_process(t_info *info)
{
	if (info)
		free_mutex(info->option);
	usleep(1000000);
	return (0);
}
