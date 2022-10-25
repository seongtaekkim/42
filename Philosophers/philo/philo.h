
#ifndef PHILO_H
 #define PHILO_H

#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
# include <stdio.h>

typedef enum s_status
{
    EATING,
    SLEEP,
    THINK
}   t_status;

typedef struct s_info
{
    pthread_t   philo;
    int         id;
    int         rfork;
    int         lfork;
    t_status    status;
}   t_info;

typedef struct s_option
{
    int     number_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     number_of_eat;
    int     *fork;
    double  start_time;
    pthread_mutex_t mutex;
    pthread_mutex_t pmutex;
}   t_option;

typedef struct s_data
{
    t_option    *option;
    t_info      info;
}   t_data;

char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

int     findRight(t_option *o, int id);
int     findLeft(t_option *o, int id);

int     check_time(double s_time, int sleep_time);
int     operate_time(double s_time);
double  cur_time();

void    sync_print(t_option *o, t_info info, char *msg);
int     _atoi(const char *str, int *flag);

#endif