#include "philo.h"

int     check_time(double s_time, int sleep_time)
{
    struct timeval tv;
    double begin, end;

    begin = s_time;

    gettimeofday(&tv, NULL);
    end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    //printf("time : %lf\n", end - begin - o.time_to_die);
    if (end - begin > sleep_time)
        return (0);
    else
        return (1);
}

int  operate_time(double s_time)
{
    struct timeval tv;
    double begin, end;

    begin = s_time;
    gettimeofday(&tv, NULL);
    end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return ((int)(end - begin));
}

double cur_time()
{
    struct timeval tv;
    double begin;

    gettimeofday(&tv, NULL);
    begin = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return (begin);
}