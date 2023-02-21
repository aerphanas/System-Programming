#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void*
add_one()
{
    int *p = (int*) malloc(sizeof(int));
    *p = (rand() % 10) + 1;
    return (void *) p;
}

int
main()
{
    srand(time(NULL));
    int *num;
    pthread_t p1;
    pthread_create(&p1, NULL, &add_one, NULL);
    pthread_join(p1, (void*)&num);

    printf("%d \n", *num);

    free(num);
    return 0;
}