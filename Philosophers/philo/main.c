
#include "philo.h"

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
}

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

double cur_time()
{
    struct timeval tv;
    double begin;

    gettimeofday(&tv, NULL);
    begin = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;

    //printf("Execution time %f\n", (end - begin) / 1000);
    return (begin);
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

    ret = -1;
    if (id == 0)
        ret = o->number_of_philo - 1;
    else
        ret = (id - 1);
    return (ret);
}


void    *t_function(void *data)
{
    t_info      info;
    t_option    *o;
    double      s_time;

    info  = ((t_data *)data)->info;
    o = ((t_data *)data)->option;
    printf("%d\n", info.id);
    s_time = cur_time();
    //printf("%lf\n",s_time);
    while (1)
    {
        // 먹는 시간 체크 // 먹는시간 끝나면, 죽는시간 할당, 시작시간 재할당
        if (info.status == THINK)
        {
            // N-1, N+1
            int l = findLeft(o, info.id);
            int r = findRight(o, info.id);
            pthread_mutex_lock(&o->mutex);
            if (o->fork[l] == 0 && o->fork[r] == 0)
            {
                printf("id : %d, l : %d, r : %d, fl : %d, fr : %d\n", info.id, l, r,o->fork[l],o->fork[r]);
                info.lfork = 1;
                info.rfork = 1;
                o->fork[l] = 1;
                o->fork[r] = 1;

                info.status = EATING;
                s_time = cur_time();
                write(1, "Eating\n", 7);
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
                write(1, "Sleep\n", 6);
            }
            // 먹는시간 체크 -> 지나면 sleep, 죽는시간 초기화.
        }
        // 자는 시간 체크
        if (info.status == SLEEP && check_time(s_time, o->time_to_sleep) == 0)
        {
            info.status = THINK;
            write(1, "think\n", 6);
        }
        // 생각하는 시간 체크
        // 죽는시간 체크 // 죽으면 리턴
        // 포크 도전 // 포크 성공하면 먹기 고고
        // 계속 체크
        if (info.status != EATING && check_time(s_time, o->time_to_die) == 0)
        {
            printf("die %d %d \n", info.id, o->fork[1]);
            o->time_to_die = 0;
            free(data);
            
            return (0);
        }
    }
    return (0);
}

void    do_eat(t_info *info, t_option o)
//void    do_eat(t_data data)
{
    int index;
    int status;
    t_data *data;

    index = 0;
    while (index < o.number_of_philo)
    {
        printf("index : %d\n",index);
        // 음식을 찾는다 => 큐 pop
        // 음식이 있으면 먹기시작한다.
        data = (t_data *)malloc(sizeof(t_data));
        data->info = info[index];
        //data.info.philo = info[index].philo;
        data->option = &o;
        //if (pthread_create(&info[index].philo, NULL, t_function, (void *)&info[index]))
        //printf("data.info  : %d\n",data.info.id);
        if (pthread_create(&info[index].philo, NULL, t_function, (void *)data))
            exit(1);
        // 먹고나서 생각한다
        // 생각하고나서 잔다. => 큐 push
        // 먹을수 있으면 다시 먹는다./
        // 죽는자가 나오면 종료한다.
        // 총 먹은 수를 만족하면 종료한다.
        index++;
        //free(data);
    }
    index = 0;
    while (index < o.number_of_philo)
    {
        pthread_join(info[index].philo, (void *)&status);
        index++;
    }
    pthread_mutex_destroy(&o.mutex);
    printf("awegawegaeawegawegaweg\n");
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