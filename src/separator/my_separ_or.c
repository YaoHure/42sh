/*
** EPITECH PROJECT, 2019
** EpitechProject (Workspace)
** File description:
** loop
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "error.h"
#include "pipe.h"
#include "sh.h"

int my_scane_separ_or(char *str)
{
    int ret = 0;
    char *res = strstr(str, "|||");

    if (res == NULL)
        ret = 0;
    else
        ret = 1;
    return (ret);
}

char **my_separ_or(char *str)
{
    char *res = strstr(str, "||");
    char **array = NULL;

    if (my_scane_separ_or(str) == 1) {
        my_putstr("Invalid null command.\n");
        return (NULL);
    }
    if (res == NULL)
        array = my_strtwa2(my_clean_str(str), '\0');
    else
        array = my_strtwa2(my_clean_str(str), '|');
    return (array);
}