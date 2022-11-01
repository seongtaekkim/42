#include "philo.h"

// 시간 + id + 상태값
t_bool    sync_print(t_info *info, char *msg)
{
    long long   s_time;

    if (pthread_mutex_lock(&info->option->pmutex))
        return (false);
    if (cur_time(&s_time) == false)
        return (false);
    /*char *a = ft_itoa((int)(s_time - info->option->start_time));
    char *b = ft_itoa(info->id);
    write(STDOUT_FILENO, a, ft_strlen(a));
    write(STDOUT_FILENO, "  ", 2);
    write(STDOUT_FILENO, b, ft_strlen(b));
    write(STDOUT_FILENO, " ", 1);*/
    write(STDOUT_FILENO, msg, ft_strlen(msg));
    write(STDOUT_FILENO, "\n", 1);
    //free(a);
    //free(b);
    if (info->status == DIE)
    {
        write(1, "diedie\n",7);
        return (false);
    }
    if (pthread_mutex_unlock(&info->option->pmutex))
        return (false);
    return (true);
}