/*
** EPITECH PROJECT, 2019
** My_ls_color functions for 42sh
** File description:
** print_ls_in_color
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

char **my_ls_color(char **array)
{
    int a = 0;
    int len = my_len_array(array);
    char **dest = malloc(sizeof(char *) * (len + 2));

    dest[a] = my_strdup(array[0]);
    a++;
    dest[a] = my_strdup("--color=auto");
    a++;
    for (int i = 1; array[i]; i++, a++) {
        dest[a] = my_strdup(array[i]);
    }
    dest[a] = NULL;
    my_free_array(array);
    return (dest);
}