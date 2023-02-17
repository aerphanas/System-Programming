#include <stdio.h>

int
main()
{
    int result = 0;
    int number[100000];
    int size_arr = sizeof(number) / sizeof(number[0]);

    for (int i = 0; i < size_arr; i++) {
        number[i] = i;
    }

    for (int i = 0; i < size_arr; i++) {
        result = result + number[i];
    }

    printf("Sum of the number is %d \n", result);
    return 0;
}