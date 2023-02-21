#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int x =0;

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
    pthread_t p1, p2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&p1, NULL, &calculate, NULL);
    pthread_create(&p2, NULL, &calculate, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("%d \n", x);
    return 0;
}