#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int
main()
{
    char number[99]; //{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < 100; i++) {
        number[i] = i;
    }
    int number_size = sizeof(number) / sizeof(number[0]);
    int fd[2];
    pipe(fd);
    // bytes written on PIPEDES[1] can be read from PIPEDES[0].

    int ps = fork();
    if (ps == 0) {
        int start, end, result;

        start = number_size / 2;
        end = number_size;

        for (int i = start; i <= end; i++)
            result = result + number[i];

        write(fd[1], &result, sizeof(result));
        close(fd[1]);
        close(fd[0]);
    } else {
        wait(NULL);

        int start, end, result;

        start = 0;
        end = number_size / 2 - 1;

        read(fd[0], &result, sizeof(result));

        for (int i = start; i <= end; i++)
            result = result + number[i];

        close(fd[0]);
        close(fd[1]);

        printf("Sum of the number is %d ", result);
    }
    return 0;
}