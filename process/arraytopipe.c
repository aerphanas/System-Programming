#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2]; // bytes written on PIPEDES[1] can be read from PIPEDES[0].
    if (pipe(fd) == -1)
        return 2;

    int id = fork();
    if (id == -1)
        return 1;

    if (id == 0)
    {
        close(fd[0]);

        int *arr = (int*) calloc(10, sizeof(int));

        int size_arr = 10;

        for (int i = 0;i < size_arr;i++)
            *(arr+i) = i;

        write(fd[1], &size_arr, sizeof(size_arr));
        write(fd[1], arr, sizeof(int)*size_arr);

        close(fd[1]);
        free(arr);
    }
    else
    {
        close(fd[1]);

        int size_arr = 0;
        read(fd[0], &size_arr, sizeof(size_arr));

        int *arr = (int*) calloc(size_arr,sizeof(int));

        read(fd[0], arr, sizeof(int)*size_arr);

        for (int i = 0; i < size_arr; i++)
            printf("%d ", *(arr+i));
        printf("\n");

        free(arr);
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}
