#ifdef linux

#include <stddef.h>
#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>

unsigned int
byte_to_megabyte(unsigned long* num);

int
main()
{
    char hostname[255];
    gethostname(hostname, sizeof(hostname));
    struct sysinfo info;
    if (sysinfo(&info) == -1)
    {
        printf("Failed to find system information \n");
        return 1;
    }

    size_t total_ram_in_mb = byte_to_megabyte(&info.totalram);
    size_t total_free_ram_in_mb = byte_to_megabyte(&info.freeram);
    size_t total_shared_ram_in_mb = byte_to_megabyte(&info.sharedram);
    size_t total_buffer_ram_in_mb = byte_to_megabyte(&info.bufferram);

    printf("Hostname \t\t\t: %s \n", hostname);
    printf("Uptime \t\t\t\t: %ld Hours / %ld Minutes / %ld Seconds \n",
            info.uptime / 3600, info.uptime / 60, info.uptime);
    printf("Number of current processes \t: %hu Process \n", info.procs);
    printf("Total usable main memory size \t: %ld MB \n", total_ram_in_mb);
    printf("Available memory size \t\t: %ld MB \n", total_free_ram_in_mb);
    printf("Amount of shared memory \t: %ld MB \n", total_shared_ram_in_mb);
    printf("Memory used by buffers \t\t: %ld MB \n", total_buffer_ram_in_mb);

    return 0;
}

unsigned int
byte_to_megabyte(unsigned long* num)
{
    return *num / 1048576;
}
#endif

#ifdef _WIN32

#include <stdio.h>

int
main()
{
    printf("program only work on linux \n");
    return 0;
}

#endif