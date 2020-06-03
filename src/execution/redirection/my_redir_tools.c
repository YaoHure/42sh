/*
** EPITECH PROJECT, 2018
** Redirection Right 42sh
** File description:
** functions for redirection right
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "my.h"
#include "redir.h"
#include "error.h"

int my_scane_redir_nbr(char *str, char *ref)
{
    int ret = 0;
    char *res = strstr(str, ref);

    if (res == NULL)
        ret = 0;
    else
        ret = 1;
    return (ret);
}

int scane_redir_right(char *str)
{
    int position = my_find_char(str, '>');

    if ((strcspn(str, ">") == 0) || (my_scane_redir_nbr(str, ">>>") == 1))
        return (1);
    if ((position == 0) || ((position + 1) == my_strlen(str)))
        return (1);
    return (0);
}

int create_file(char *str, int i)
{
    int fdop = 0;

    if (i == 1)
        fdop = open(my_clean_str(str), O_CREAT | O_WRONLY |
        O_TRUNC, 0666);
    else if (i == 2)
        fdop = open(my_clean_str(str), O_CREAT | O_WRONLY |
        O_APPEND, 0666);
    return (fdop);
}