/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** which.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "cd.h"

int which_loop(char **tab, char **tab_path, int j, int compt)
{
    char *file[2];
    int compteur = 0;
    int y = 0;
    int fail = 0;

    file[1] = NULL;
    while (tab_path[y]) {
        file[0] = my_strcat(tab_path[y], "/");
        file[0] = my_strcat(file[0], tab[j]);
        if (!access(file[0], X_OK || F_OK)) {
            compteur = 1;
            printf("%s/%s\n", tab_path[y], tab[j]);
            break;
        }
        y++;
    } if (compteur != 1 && compt == 0) {
        fail ++;
        fprintf(stderr, "%s%s", tab[j], "Command not found.\n");
    }
    return (fail);
}

int print_which_built(char **built, char **tab, int j, int compt)
{
    for (int i = 0; built[i]; i++) {
        if (my_strcmp(built[i], tab[j]) == 0) {
            compt = 1;
            printf("%s: shell built-in command.\n", tab[j]);
        }
    }
    return (compt);
}

int my_which(char **built, char **tab_path, char **tab)
{
    int fail = 0;
    int compt = 0;

    if (!tab[1]) {
        printf("which: Too few arguments.\n");
        return (0);
    }
    for (int j = 1; tab[j]; j++) {
        compt = 0;
        if ((compt = print_which_built(built, tab, j, compt)) != 1)
            fail += which_loop(tab, tab_path, j, compt);
    }
    if (fail > 0)
        return (1);
    else
        return (0);
}