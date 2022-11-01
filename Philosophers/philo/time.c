#include "philo.h"

int     check_time(double s_time, int sleep_time)
{
    struct timeval tv;
    double begin, end;

    begin = s_time;

    gettimeofday(&tv, NULL);
    end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    if (end - begin > sleep_time)
        return (0);
    else
        return (1);
}

t_bool  cur_time(long long *begin)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (false);
    *begin = (long long )((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
    return (true);
}

t_bool	wait_time(long long start, long long time)
{
	long long	cur;

	while (1)
	{
		if (cur_time(&cur) == false)
			return (false);
		if (cur >= start + time)
			break ;
		if (usleep(10) == -1)
			return (false);
	}
    return (true);
}