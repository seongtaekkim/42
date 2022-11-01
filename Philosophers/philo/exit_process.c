#include "philo.h"

/*
로직 중간중간 리턴 로직 추가해서 프리에 문제 없는지 테스트 필수임.
*/
static void free_mutex(t_info *info)
{
    int index;

    index = 0;
    if (info)
    {
        while (info->option->number_of_philo > index)
        {
            pthread_mutex_destroy(&info->option->fork[index]);
            index++;
        }
    }
    pthread_mutex_destroy(&info->option->pmutex);
    pthread_mutex_destroy(&info->option->main_mutex);
}

int exit_process(t_info *info)
{
    if (info)
        free_mutex(info);
    return (0);
}