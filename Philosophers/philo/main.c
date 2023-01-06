/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:25:27 by staek             #+#    #+#             */
/*   Updated: 2023/01/06 11:57:21 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	init_mutax(t_option *o)
{
	int	index;

	index = 0;
	if (!s_malloc((void **)&o->fork
			, sizeof(pthread_mutex_t) * o->number_of_philo))
		return (false);
	while (index < o->number_of_philo)
		if (pthread_mutex_init(&o->fork[index++], NULL))
			return (false);
	if (pthread_mutex_init(&o->main_mutex, NULL))
		return (false);
	if (pthread_mutex_init(&o->pmutex, NULL))
		return (false);
	return (true);
}

static t_bool	init(int num, char *argv[], t_option *o)
{
	int	index;

	index = 0;
	if (_atoi(argv[1], &o->number_of_philo) == false
		|| _atoi(argv[2], &o->time_to_die) == false
		|| _atoi(argv[3], &o->time_to_eat) == false
		|| _atoi(argv[4], &o->time_to_sleep) == false)
		return (false);
	if (num == 6&& (_atoi(argv[5], &o->number_of_eat) == false
			|| o->number_of_eat == 0))
		return (false);
	o->num_of_eat_count_down = o->number_of_philo;
	if (!init_mutax(o))
		return (false);
	return (true);
}

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
		if (cur_time(&info->philo_time) == false)
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

void	*func_monitor_t(void *data)
{
	t_info		*info; 
	long long	s_time;

	info = (t_info *)data;
	if (wait_time(info->option->time_to_die - 10) == false)
		pthread_mutex_unlock(&info->option->main_mutex);
	while (1)
	{
		if (cur_time(&s_time) == false)
			pthread_mutex_unlock(&info->option->main_mutex);
		if (s_time > (info->philo_time
				+ (long long)info->option->time_to_die))
		{
			sync_print(info, "is died", DIE);
			return (NULL);
		}
		if (info->option->num_of_eat_count_down == 0)
		{
			sync_print(info, "is completed", COMPLETED);
			return (NULL);
		}
	}
	return (NULL);
}

t_bool	do_eat(t_info *info, t_option *o)
{
	int	index;

	index = 0;
	if (pthread_mutex_lock(&o->main_mutex))
		return (exit_process(info));
	if (cur_time(&o->start_time) == false)
		pthread_mutex_unlock(&o->main_mutex);
	while (index < o->number_of_philo)
		info[index++].option = o;
	index = 0;
	while (index < o->number_of_philo)
	{
		if (cur_time(&info[index].philo_time) == false)
			pthread_mutex_unlock(&info->option->main_mutex);
		if (pthread_create(&info[index].philo, NULL, func_eating_t
				, &info[index]) || pthread_detach(info[index].philo))
			return (false);
		if (pthread_create(&info[index].monitor, NULL, func_monitor_t
				, &info[index]) || pthread_detach(info[index].monitor))
			return (false);
		index++;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_option	option;
	t_info		*info;
	int			index;

	if (argc != 5 && argc != 6)
		return (0);
	if (!init(argc, argv, &option))
		return (0);
	index = 0;
	if (!s_malloc((void **)&info, sizeof(t_info) * (option.number_of_philo)))
		return (0);
	while (index < option.number_of_philo)
	{
		info[index].id = index;
		info[index].lfork = index;
		info[index].rfork = (index + 1) % option.number_of_philo;
		info[index].philo_num_of_eat = 0;
		index++;
	}
	if (!do_eat(info, &option))
		return (exit_process(info));
	if (pthread_mutex_lock(&option.main_mutex))
		return (exit_process(info));
	return (exit_process(info));
}
