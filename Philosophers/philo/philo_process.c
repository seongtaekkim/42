#include "philo.h"

t_bool take_fork(t_info *info)
{
    if (!pthread_mutex_lock(&info->option->fork[info->lfork]))
    {
        sync_print(info, "has taken a fork");
        if (!pthread_mutex_lock(&info->option->fork[info->rfork]))
            sync_print(info, "has taken a fork");
    }
    else
        return (false);
    return (true);
}

t_bool  eat_philo()
{
    return (true);
}

t_bool  put_fork(t_info *info)
{
    if (pthread_mutex_unlock(&info->option->fork[info->lfork]))
        return (false);
    if (pthread_mutex_unlock(&info->option->fork[info->rfork]))
        return (false);
    return (true);
}

t_bool  sleep_philo()
{
    return (true);
}

t_bool  think_philo()
{
    return (true);
}