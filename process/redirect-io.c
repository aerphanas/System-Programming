#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0777);

    if (fd == -1){
        return 1;
    }

    // duplicate output.txt to stdout
    int fd2 = dup2(fd, STDOUT_FILENO);
    if (fd2 == -1) {
        return 1;
    }

    close(fd);
    
    int exec = execlp("echo", "echo", "\"Hello World\"", NULL);
    if (exec == -1)
        return 1;
    
    return 0;
}