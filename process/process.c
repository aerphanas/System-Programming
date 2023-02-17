#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int
main()
{
  int id = fork();
  int p;

  if (id == 0)
    sleep(1);

  if (id == 0)
    printf("This is child with id %d and parent %d \n", getpid(), getppid());
  else
    printf("This is parrent with id %d \n", getpid());

  int res = wait(NULL);
  if (res == -1)
    printf("No Child to wait \n");
  else
    printf("%d finnish execution \n", res);

  return 0;
}
