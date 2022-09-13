
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
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_eat;
}   t_option;

typedef struct s_data
{
    t_option    option;
    t_info      *info;
}   t_data;

#endif