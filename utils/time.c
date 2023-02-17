#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>

int
main()
{
    // get LANG from env var and set
    char* locale = getenv("LANG");
    setlocale(LC_ALL, locale);

    // get current time 
    time_t times = time(NULL);
    struct tm *local_time = localtime(&times);

    // print time
    wchar_t buff[40];
    wcsftime(buff, sizeof(buff), L"%X - %b %d %Y", local_time);
    printf("%ls \n", buff);

    return 0;
}