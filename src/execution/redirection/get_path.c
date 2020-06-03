/*
** EPITECH PROJECT, 2018
** Environment redir and pipe functions for 42sh
** File description:
** Catching env variables
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "redir.h"

char *my_getenv(char **env, char *str)
{
    char *dest;
    char **arg_line;

    for (int y = 0; env[y]; y++) {
        if (my_strncmp(env[y], str, strlen(str))) {
            arg_line = my_strtwa2(env[y], '=');
            if (arg_line[1] != NULL)
                dest = my_strdup(arg_line[1]);
            else
                dest = NULL;
            break;
        }
    }
    return (dest);
}

char *get_path(char **tab, char *comd)
{
    char *meme = NULL;

    for (int i = 0; tab[i] != NULL; i++) {
        meme = my_strcat_mini(tab[i], comd, '/');
        if (access(meme, F_OK | X_OK) == 0)
            return (meme);
    }
    return (NULL);
}