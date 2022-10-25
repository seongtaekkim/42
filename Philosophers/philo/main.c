#include "philo.h"

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
    o->fork = (int *)malloc(sizeof(int) * o->number_of_philo);
    o->start_time = cur_time();
    memset(o->fork, 0, o->number_of_philo);
    if (num == 6)
        o->number_of_eat = _atoi(argv[5], &flag);
    if (flag == 0) // 예외처리 뭔가 이상함. 
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


/*
    내가 마지막 번호이면 0번을 리턴
    마지막이 아니면 다음번호 리턴
*/
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

/*
    내 id
*/
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
    //printf("inini : id : %d, %d %d %d %d %d\n", info.id,  o->fork[4],o->fork[6],o->fork[7],o->fork[8],o->fork[9]);
    while (1)
    {
        if (info.status == THINK)
        {
            int l = findLeft(o, info.id);
            int r = findRight(o, info.id);
            
            pthread_mutex_lock(&o->mutex);
            if (o->fork[l] == 0)
            {
                //o->fork[l] = 1;
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
                   // o->fork[l] = 0;
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

        /*
            누군가 죽었을 때 
            쓰레드를 종료하는 로직을 
            모니터로 만들해야 함 ..
        */
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
        //printf("inini2 : %d %d \n", data->option->fork[9], o.fork[9]);
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