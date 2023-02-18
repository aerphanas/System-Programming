#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main()
{
    int id = fork();
    if (id == -1)
        return 1;
    if (id == 0)
    {
        int exe = execlp("cat", "cat", "/etc/os-release", NULL);
        if (exe == -1)
            return 1;
    } else {
        int cstatus;
        wait(&cstatus);
        if (WIFEXITED(cstatus)){
            int status_code = WEXITSTATUS(cstatus);
            if (status_code == 0)
                printf("Success \n");
            else
                printf("failure \n");
            printf("child execute return %d \n", status_code);
        }
    }
    return 0;
}