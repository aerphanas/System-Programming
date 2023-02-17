#include <stdio.h>
#include <unistd.h>

int
main()
{
    int fd[2];
    // bytes written on PIPEDES[1] can be read from PIPEDES[0].

    if (pipe(fd) == -1)
        printf("error when creating pipe");

    int p = fork();
    if (p == 0) {
        int x;
        printf("tolong masukan angka : ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(x));
        
        close(fd[1]);
        close(fd[0]);
    } else {
        int y;
        read(fd[0], &y, sizeof(y));
        printf("anda memasukan angka %d", y);

        close(fd[0]);
        close(fd[1]);
    }

    return 0;
}