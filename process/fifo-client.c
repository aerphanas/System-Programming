#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int
main()
{
    int fd = open("myfifo", O_RDONLY);
    char x[13];
    read(fd, x, sizeof(x));
    printf("%s", x);
    close(fd);
    return 0;
}