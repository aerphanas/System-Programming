#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int
main()
{
    int pd = fork();
    if (pd == -1)
    {
        printf("cannot creating process");
        return 0;
    }

    if (pd == 0)
    {
        printf("my pid is : %d \n", getpid());
        printf("input any number : ");
        int num;
        scanf("%d", &num);
        printf("your input is %d \n", num);
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0) {
                printf("Program exit %d \n", exit_status);
                return exit_status;
            } else {
                printf("program exit %d \n", exit_status);
                return exit_status;
            }
        }
    }
    return 0;
}