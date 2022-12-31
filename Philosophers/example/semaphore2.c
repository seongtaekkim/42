#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int sum = 0;  // a shared variable

sem_t *sem;

void *counter(void *param)
{
    int k;
    for (k = 0; k < 10000; k++)
    {
        /* entry section */
        sem_wait(sem);
        /* critical section */
        sum++;
        /* exit section */
        sem_post(sem);
        /* remainder section */
    }
    pthread_exit(0);
}

int main() {
    pthread_t tid[5]; int i;
    //sem_init(&sem, 0, 1);
    sem = sem_open("test_sem", O_CREAT | O_EXCL, 9888, 1);
    for (i = 0; i < 5; i++)
        pthread_create(&tid[i], NULL, counter, NULL);
    for (i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);

    sem_close(sem); // 세마포어 종료 및 할당한 자원 해제
	sem_unlink("test_sem"); // 세마포어 객체 해제
    printf("sum = %d\n", sum);
}