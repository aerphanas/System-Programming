#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int
main()
{
    int pd = fork();
    if (pd == 0) {
        while (1) {
            printf("Hello...\n");
            usleep(50000);
        }
    } else {
        printf("send stop signal \n");
        kill(pd, SIGSTOP);
        sleep(1);
        printf("send continue signal \n");
        kill(pd, SIGCONT);
        sleep(1);
        printf("send stop signal \n");
        kill(pd, SIGSTOP);
        sleep(1);
        printf("send continue signal \n");
        kill(pd, SIGCONT);
        sleep(1);
        printf("send kill signal \n");
        kill(pd, SIGKILL);
        wait(NULL);
        printf("end of output\n");
    }
    return 0;
}