#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void*
test_threads()
{
    printf("begin...\n");
    sleep(2);
    printf("end..\n");
}

int
main()
{
    pthread_t p1, p2;
    pthread_create(&p1, NULL, &test_threads, NULL);
    pthread_create(&p2, NULL, &test_threads, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}