#include <stdio.h>
#include <time.h>
#include "print_module.h"

void print_log(char (*print)(char), char* message)
{
    time_t rawtime;
    struct tm* timeinfo;
    char time_str[9]; 

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(time_str, sizeof(time_str), "%H:%M:%S", timeinfo);

    const char* prefix = Log_prefix;
    while (*prefix)
    {
        print(*prefix);
        prefix++;
    }

    for (int i = 0; i < 8; i++) 
    {
        print(time_str[i]);
    }

    print(' ');

    while (*message)
    {
        print(*message);
        message++;
    }

    print('\n');
}
