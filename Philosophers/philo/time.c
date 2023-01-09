/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:25:48 by staek             #+#    #+#             */
/*   Updated: 2023/01/09 19:55:16 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

t_bool	cur_time(long long *begin)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (false);
	*begin = (long long )((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
	return (true);
}

t_bool	wait_time(long long time)
{
	long long	cur;
	long long	start;

	if (cur_time(&start) == false)
		return (false);
	while (1)
	{
		if (cur_time(&cur) == false)
			return (false);
		if (cur - start >= time)
			break ;
		if (usleep(10) == -1)
			return (false);
	}
	return (true);
}
