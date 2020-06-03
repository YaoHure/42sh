/*
** EPITECH PROJECT, 2018
** print the current time in the prompt
** File description:
** my_print_time.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include "my.h"
#include "sh.h"

int my_print_time(void)
{
    time_t rawtime;
    struct tm * timeinfo;
    char *cur_time;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    my_putstr("\033[0;35m");
    my_putstr(" |");
    cur_time = strtok(asctime(timeinfo), "\n");
    if (cur_time != NULL)
        my_putstr(cur_time);
    my_putstr("|");
    my_putstr("\033[0m");
    return (0);
}
