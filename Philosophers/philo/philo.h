/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:25:04 by staek             #+#    #+#             */
/*   Updated: 2023/01/09 13:59:04 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>

typedef enum s_status
{
	TAKEN,
	EATING,
	SLEEP,
	THINK,
	DIE,
	COMPLETED
}	t_status;

typedef struct s_option
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	int				num_of_eat_count_down;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	pmutex;
	pthread_mutex_t	main_mutex;
	pthread_t		monitor;
}	t_option;

typedef struct s_info
{
	pthread_t	philo;
	int			id;
	int			rfork;
	int			lfork;
	t_status	status;
	long long	philo_time;
	int			philo_num_of_eat;
	t_option	*option;
}	t_info;

typedef enum s_bool
{
	false,
	true
}	t_bool;

char	*ft_itoa(long long n);
size_t	ft_strlen(const char *s);
t_bool	cur_time(long long *begin);
t_bool	wait_time(long long time);
t_bool	sync_print(t_info *info, char *msg, t_status status);
t_bool	_atoi(const char *str, int *output);
t_bool	take_fork(t_info *info);
t_bool	put_fork(t_info *info);;
int		exit_process(t_info *info);
int		s_malloc(void **ptr, size_t size);
void	*func_monitor_t(void *data);
void	*func_eating_t(void *data);
int		free_mutex(t_option *option);

#endif