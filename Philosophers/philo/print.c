#include "philo.h"

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


   // write(1, "       ", 7);
    
    // char *l = ft_itoa(findLeft(o, info.id));
    // char *r = ft_itoa(findRight(o, info.id));
    // write(1, l, ft_strlen(l));
    // write(1, "  ", 2);
    // write(1, r, ft_strlen(r));

    // char *s = ft_itoa(o->fork[findLeft(o, info.id)]);
    // char *t = ft_itoa(o->fork[findRight(o, info.id)]);
    // write(1, "  ", 2);
    // write(1, s, ft_strlen(s));
    // write(1, "  ", 2);
    // write(1, t, ft_strlen(t));


    write(1, "\n", 1);
    pthread_mutex_unlock(&o->pmutex);

}