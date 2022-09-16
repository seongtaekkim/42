
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

static int	_atoi(const char *str, int *flag)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == 0)
		*flag = 0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str++ - '0');
		else
		{
			*flag = 0;
			return (-1);
		}
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			*flag = 0;
	}
	return (result * sign);
}

static void init(int num, char  *argv[], t_option *o, t_info **info)
//static void init(int num, char  *argv[], t_data *data)
{
    int flag;
    int index;

    index = 0;
    flag = 1;
    o->number_of_philo = _atoi(argv[1], &flag);
    o->time_to_die = _atoi(argv[2], &flag);
    o->time_to_eat = _atoi(argv[3], &flag);
    o->time_to_sleep = _atoi(argv[4], &flag);
    o->fork = (int *)malloc(sizeof(o->number_of_philo));
    o->start_time = cur_time();
    memset(o->fork, 0, o->number_of_philo);
    if (num == 6)
        o->number_of_eat = _atoi(argv[5], &flag);
    if (flag == 0)
        exit(0);
    *info = (t_info *)malloc(sizeof(t_info) * (o->number_of_philo));
    if (!(*info))
        exit(1);
    while (index < o->number_of_philo)
    {
        (*info)[index].id = index;
        (*info)[index].rfork = 0;
        (*info)[index].lfork = 0;
        (*info)[index].status = THINK;
        index++;
    }
    pthread_mutex_init(&o->mutex, NULL);
    pthread_mutex_init(&o->pmutex, NULL);
}

int findRight(t_option *o, int id)
{
    int ret;

    ret = -1;
    if (o->number_of_philo -1 == id)
        ret = 0;
    else
        ret = (id + 1);
    return (ret);
}

int findLeft(t_option *o, int id)
{
    int ret;
    (void)o;
    /* ret = -1;
    if (o->number_of_philo == 2)
    {
        ret = id;
    }
    else if (id == 0)
        ret = o->number_of_philo - 1;
    else
        ret = (id); */

    ret = id;
    return (ret);
}


// 시간 + id + 상태값
void    sync_print(t_option *o, t_info info, char *msg)
{
    pthread_mutex_lock(&o->pmutex);
    int time = operate_time(o->start_time);
    char *a = ft_itoa(time);
    char *b = ft_itoa(info.id);
    write(1, a, ft_strlen(a));
    write(1, "  ", 2);
    write(1, b, ft_strlen(b));
    write(1, "  ", 2);
    write(1, msg, ft_strlen(msg));
    write(1, "  ", 2);
    char *l = ft_itoa(findLeft(o, info.id));
    char *r = ft_itoa(findRight(o, info.id));
    write(1, l, ft_strlen(l));
    write(1, "  ", 2);
    write(1, r, ft_strlen(r));
    char *s = ft_itoa(o->fork[findLeft(o, info.id)]);
    char *t = ft_itoa(o->fork[findRight(o, info.id)]);
    write(1, "  ", 2);
    write(1, s, ft_strlen(s));
    write(1, "  ", 2);
    write(1, t, ft_strlen(t));
    write(1, "\n", 1);
    pthread_mutex_unlock(&o->pmutex);

}

void    *t_function(void *data)
{
    t_info      info;
    t_option    *o;
    double      s_time;

    info  = ((t_data *)data)->info;
    o = ((t_data *)data)->option;
    s_time = cur_time();
    if (info.id % 2 == 0)
       usleep(50);
    //printf("inini : %d %d %d %d %d\n",  o->fork[0],o->fork[1],o->fork[2],o->fork[3],o->fork[4]);
     while (1)
    {
        if (info.status == THINK)
        {
            int l = findLeft(o, info.id);
            int r = findRight(o, info.id);
            
                pthread_mutex_lock(&o->mutex);
            if (o->fork[l] == 0)
            {
                o->fork[l] = 1;
                if (o->fork[r] == 0)
                {
                    sync_print(o, info, "is taken a fork");
                    //printf("id : %d, l : %d, r : %d, fl : %d, fr : %d\n", info.id, l, r,o->fork[l],o->fork[r]);
                    
                    info.lfork = 1;
                    info.rfork = 1;
                    o->fork[l] = 1;
                    o->fork[r] = 1;

                    info.status = EATING;
                    s_time = cur_time();
                    sync_print(o, info, "is eating");
                }
                else
                {
                    o->fork[l] = 0;
                }
            }
                pthread_mutex_unlock(&o->mutex);
            
        }
        if (info.status == EATING)
        {
            if (check_time(s_time, o->time_to_eat) == 0)
            {
                info.lfork = 0;
                info.rfork = 0;
                o->fork[findLeft(o, info.id)] = 0;
                o->fork[findRight(o, info.id)] = 0;

                info.status = SLEEP;
                s_time = cur_time();
                sync_print(o, info, "is sleeping");
            }
        }
        if (info.status == SLEEP)
        {
            if (check_time(s_time, o->time_to_sleep) == 0)
            {
                info.status = THINK;
                sync_print(o, info, "is thinking");
            }
        }

        if (info.status != EATING && check_time(s_time, o->time_to_die) == 0)
        {
            //printf("die %d %d \n", info.id, o->fork[1]);
            o->time_to_die = 0;
            sync_print(o, info, "is died");
            free(data);
            exit(1);
        }
    } 
    return (0);
}

void    do_eat(t_info *info, t_option o)
{
    int index;
    int status;
    t_data *data;

    index = 0;
    int i = 0;
    while (i < o.number_of_philo)
        o.fork[i++] = 0;

    while (index < o.number_of_philo)
    {
        data = (t_data *)malloc(sizeof(t_data));
        data->info = info[index];
        data->option = &o;
        printf("inini2 : %d %d \n", data->option->fork[9], o.fork[9]);
        if (pthread_create(&info[index].philo, NULL, t_function, (void *)data))
            exit(1);
        index++;
    }
    index = 0;
    while (index < o.number_of_philo)
    {
        pthread_join(info[index].philo, (void *)&status);
        index++;
    }
    pthread_mutex_destroy(&o.mutex);
    pthread_mutex_destroy(&o.pmutex);
}

int main(int argc, char *argv[])
{
    t_option    option;
    t_info      *info;

    if (argc != 5 && argc != 6)
        return (0);
    init(argc, argv, &option, &info);
    do_eat(info, option);
    return (0);
}