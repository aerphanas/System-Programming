#include <stdio.h>
#include <pthread.h>

#define NUM 5

int x = 0;
pthread_mutex_t mutex;

void*
calculate()
{
    for (int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
}

int
main()
{
    pthread_t pt[NUM];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM; i++)
        pthread_create(pt+i, NULL, &calculate, NULL);

    for (int i = 0; i < NUM; i++) {
        pthread_join(*(pt+i), NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("%d \n",x);
    return 0;
}