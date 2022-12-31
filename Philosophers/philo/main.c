#include "philo.h"

static t_bool init_mutax(t_option *o)
{
    int index;

    index = 0;
    o->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * o->number_of_philo);
    if (!o->fork)
        return (false);
    while (index < o->number_of_philo)
        if (pthread_mutex_init(&o->fork[index++], NULL))
            return (false);
    if (pthread_mutex_init(&o->main_mutex, NULL))
        return (false);
    if (pthread_mutex_init(&o->pmutex, NULL))
        return (false);
    return (true);
}

static t_bool init(int num, char  *argv[], t_option *o)
{
    int index;

    index = 0;
    if (_atoi(argv[1], &o->number_of_philo) == false
    || _atoi(argv[2], &o->time_to_die) == false
    || _atoi(argv[3], &o->time_to_eat) == false
    || _atoi(argv[4], &o->time_to_sleep) == false)
        return (false);
    if (num == 6 && _atoi(argv[5], &o->number_of_eat) == false)
        return (false);
    if (!init_mutax(o))
        return (false);
    return (true);
}

void    *func_eating_t(void *data)
{
    t_info      *info;
    info = (t_info *)data;

    if (info->id % 2 == 0)
        if (wait_time(info->philo_time, 50) == false) 
            pthread_mutex_unlock(&info->option->main_mutex);
    while (1)
    {   

        if (!take_fork(info))
        {
            pthread_mutex_unlock(&info->option->main_mutex);
        }
        if (cur_time(&info->philo_time) == false)
            pthread_mutex_unlock(&info->option->main_mutex);

        sync_print(info, "is eating");
        
        if (wait_time(info->philo_time, info->option->time_to_eat) == false) 
            pthread_mutex_unlock(&info->option->main_mutex);
        // 최최 먹는 양 측정 후 만족하면 컴플릿 
        
        if (!put_fork(info))
            pthread_mutex_unlock(&info->option->main_mutex);
        if (cur_time(&info->philo_time) == false)
            pthread_mutex_unlock(&info->option->main_mutex);

        sync_print(info, "is sleeping");

        //usleep(info->option->time_to_sleep * 1000); // 현재시간 기준 비교구문 추가 -> usleep : 시간밀림
        if (wait_time(info->philo_time, info->option->time_to_sleep) == false) 
            pthread_mutex_unlock(&info->option->main_mutex);
            
        sync_print(info, "is thinking");
    } 
    return (0);
}

void *func_monitor_t(void *data)
{
    t_info      *info;
    long long   s_time;
    info = (t_info *)data;
    int index;
    int num;
    if (cur_time(&s_time) == false)
                pthread_mutex_unlock(&info[0].option->main_mutex);
    if (wait_time(s_time, info[0].option->time_to_die - 10) == false) 
            pthread_mutex_unlock(&info->option->main_mutex);
    while (1)
    {
        index = 0;
        num = info[index].option->number_of_philo;
        while (index < num)
        {
            if (cur_time(&s_time) == false)
                pthread_mutex_unlock(&info[index].option->main_mutex);
            if (s_time >= (info[index].philo_time + (long long)info[index].option->time_to_die))
            {
                info[index].status = DIE;
                sync_print(&info[index], "is died");
                write(1,"000failed\n", 7);
                //printf("%lld, %lld",s_time,info[index].philo_time );
                if (pthread_mutex_unlock(&info[index].option->main_mutex) != 0)
                    write(1,"failed\n", 7);
                else
                    write(1,"successed\n",10);
                return (NULL);
            }
            index++;
        }
    }
    return (NULL);
}

t_bool  do_eat(t_info *info, t_option *o)
{
    int index;

    index = 0; 
    if (cur_time(&o->start_time) == false)
        pthread_mutex_unlock(&o->main_mutex);
    while (index < o->number_of_philo)
        info[index++].option = o;
    index = 0;
    while (index < o->number_of_philo)
    {
        if (cur_time(&info[index].philo_time) == false)
            pthread_mutex_unlock(&info->option->main_mutex);
        if (pthread_create(&info[index].philo, NULL, func_eating_t, &info[index])
            || pthread_detach(info[index].philo))
            return (false);
        index++;
    }
    if (pthread_create(&o->monitor, NULL, func_monitor_t, (void *)info)
        || pthread_detach(o->monitor))
        return (false);
    

    // join 은 필요없다.
    // detach 로 스레드와 메인스레드를 분리하여
    // 메인스레드 종료 시 자원회수를 진행할 것이다
    // 대신에 스레다가 하나라도 종료되면 리턴되어 종료될 것이다.
    /*
    index = 0;
    while (index < o.number_of_philo)
    {
        pthread_join(info[index].philo, (void *)&status);
        index++;
    }
    */
   return (true);
}

int main(int argc, char *argv[])
{
    t_option    option;
    t_info      *info;

    if (argc != 5 && argc != 6)
        return (0);

    if (!init(argc, argv, &option))
        return (0);

    int index = 0;
    info = (t_info *)malloc(sizeof(t_info) * (option.number_of_philo));
    if (!(info))
        return (false);
    while (index < option.number_of_philo)
    {
        info[index].id = index;
        info[index].lfork = index;
        info[index].rfork = (index + 1) % option.number_of_philo;
        index++;
    }
    if (pthread_mutex_lock(&option.main_mutex))
        return (exit_process(info));
    if (!do_eat(info, &option))
        return (exit_process(info));
    // 메인스레드가 여기서 멈춰있다가, 다른 스레드중 하나가 락을 풀어버리면 메인스레드가 여기를 통과하고 종료한다.
    //write(1, "main thread sleep\n", 18);
    if (pthread_mutex_lock(&option.main_mutex))
        return (exit_process(info));
   // write(1, "main thread exit\n", 17);
    
    return (exit_process(info));
}
