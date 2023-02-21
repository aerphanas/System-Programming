#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int
main()
{
    int fd[2]; // bytes written on PIPEDES[1] can be read from PIPEDES[0].
    if (pipe(fd))
        return 1;
    int id = fork();
    if (id == -1)
        return 2;
    
    if (id == 0)
    {
        char name[100];
        printf("What is your name : ");
        fgets(name, 100, stdin);
        name[strlen(name) - 1] = '\0';
        int length = strlen(name) + 1;

        write(fd[1], &length, sizeof(int));
        write(fd[1], name, sizeof(char) * length);

        close(fd[0]);
        close(fd[1]);
    }
    else
    {
        char name[100];
        int length;

        read(fd[0],&length, sizeof(int));
        read(fd[0], name, sizeof(char) * length);

        printf("received : %s \n", name);

        close(fd[0]);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}