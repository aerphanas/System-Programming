#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>


int
main()
{
    printf("creating fifo \n");
    if (mkfifo("myfifo", 0777) == -1)
    {
        if (errno != EEXIST) {
        printf("failed to create fifo file \n");
        return 1;
        }
    }
    printf("opening fifo \n");
    int fd = open("myfifo", O_WRONLY);
    char x[] = "Hello World\n";
    write(fd, &x, sizeof(x));
    printf("closing fifo \n");
    close(fd);
    return 0;
}