#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void*
add_one(void *num)
{
    int *p = (int*)malloc(sizeof(int));
    *p = (*(int*)num)+1;
    printf("%d in thread \n", *(int*)p);
    return (void*)p;
}

int
main()
{
    int x = 5;
    int *y;
    pthread_t th;
    pthread_create(&th, NULL, &add_one, &x);
    pthread_join(th, (void*)&y);

    printf("%d in main \n", *y);
    free(y);
    return 0;
}