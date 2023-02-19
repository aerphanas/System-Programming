#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void
handle_signal(int sig)
{
    printf("interupted");
}

int
main()
{
    struct sigaction sa;
    sa.sa_handler = &handle_signal;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);

    int num;
    printf("enter number : ");
    scanf("%d", &num);
    printf("you enter %d \n", num);
    return 0;
}
