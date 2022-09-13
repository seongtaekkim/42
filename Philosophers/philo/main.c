
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

//static void init(int num, char  *argv[], t_option *o, t_info **info)
static void init(int num, char  *argv[], t_data *data)
{
    int flag;
    int index;

    index = 0;
    flag = 1;
    data->option.number_of_philo = _atoi(argv[1], &flag);
    data->option.time_to_die = _atoi(argv[2], &flag);
    data->option.time_to_eat = _atoi(argv[3], &flag);
    data->option.time_to_sleep = _atoi(argv[4], &flag);
    if (num == 6)
        data->option.number_of_eat = _atoi(argv[5], &flag);
    if (flag == 0)
        exit(0);
    data->info = (t_info *)malloc(sizeof(t_info) * (data->option.number_of_philo));
    if (!(data->info))
        exit(1);
    while (index < data->option.number_of_philo)
    {
        (data->info)[index].id = index;
        (data->info)[index].rfork = 0;
        (data->info)[index].lfork = 0;
        (data->info)[index].status = THINK;
        index++;
    }
}

int     check_time(double s_time, t_info *info)
{
    //(void)info;
    struct timeval tv;
    double begin, end;

    begin = s_time;

    gettimeofday(&tv, NULL);
    end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return (end - begin + 1);
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

void    *t_function(void *info)
{
    printf("%d\n", ((t_info *)info)->id);
    double s_time;

    s_time = cur_time();
    //printf("%lf\n",s_time);
    while (1)
    {
        // 먹는 시간 체크
        // 자는 시간 체크
        // 생각하는 시간 체크
        // 포크 도전
        // 계속 체크
        if (check_time(s_time, (t_info *)info))
            return (0);
    }
    return (0);
}

//void    do_eat(t_info *info, t_option o)
void    do_eat(t_data data)
{
    int index;
    int status;

    index = 0;
    while (index < data.option.number_of_philo)
    {
        printf("index : %d\n",index);
        // 음식을 찾는다 => 큐 pop
        // 음식이 있으면 먹기시작한다.
        if (pthread_create(&data.info[index].philo, NULL, t_function, (void *)&data.info[index]))
            exit(1);
        // 먹고나서 생각한다
        // 생각하고나서 잔다. => 큐 push
        // 먹을수 있으면 다시 먹는다./
        // 죽는자가 나오면 종료한다.
        // 총 먹은 수를 만족하면 종료한다.
        index++;
    }
    index = 0;
    while (index < data.option.number_of_philo)
    {
        pthread_join(data.info[index].philo, (void *)&status);
        index++;
    }
}

int main(int argc, char *argv[])
{
    t_data      data;
   // t_option    option;
    //t_info      *info;

    if (argc != 5 && argc != 6)
        return (0);
    //init(argc, argv, &option, &info);
    init(argc, argv, &data);
    //do_eat(info, option);
    do_eat(data);
    return (0);
}