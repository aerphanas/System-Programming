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
        kill(pd, SIGSTOP);
        sleep(1);
        kill(pd, SIGCONT);
        sleep(1);
        kill(pd, SIGSTOP);
        sleep(1);
        kill(pd, SIGCONT);
        sleep(1);
        kill(pd, SIGKILL);
        wait(NULL);
    }
    return 0;
}