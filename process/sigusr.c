#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int x = 0;

void
sigur_handle(int sr)
{
    if (x == 0)
    {
        printf("\nHINT : multiplication is just repetitive addition \n");
        printf("what is 3 * 5 ? ");
    }
}

int
main()
{
    int id = fork();
    if (id == -1)
        return 1;

    if (id == 0)
    {
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else
    {
        struct sigaction sa;
        sa.sa_handler = &sigur_handle;
        sa.sa_flags = SA_RESTART;
        sigaction(SIGUSR1, &sa, NULL);

        printf("what is 3 * 5 ? ");
        scanf("%d", &x);
        if (x == 15)
            printf("correct \n");
        else
            printf("wrong \n");
    }

    return 0;
}