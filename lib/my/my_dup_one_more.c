/*
** EPITECH PROJECT, 2019
** dup tab
** File description:
** by Quentin Lavieville
*/

#include <stdlib.h>
#include "../../include/my.h"

int get_nb_tab_line(char **array)
{
    int line = 0;

    while (array[line] != NULL) {
        line++;
    }
    return (line);
}

char **my_dup_tab(char **tab)
{
    char **dest = malloc(sizeof(char *) * (get_nb_tab_line(tab) + 1));
    int line = 0;

    if (!dest)
        return (NULL);
    for (int x = 0; tab[x]; x++, line++) {
        dest[line] = malloc(sizeof(char) * (my_strlen(tab[x]) + 1));
        if (!dest[line])
            return (NULL);
        dest[line] = tab[x];
        dest[line][my_strlen(tab[x])] = '\0';
    }
    dest[line] = NULL;
    return (dest);
}

char **my_dup_one_more(char **tab)
{
    char **dest = malloc(sizeof(char *) * (get_nb_tab_line(tab) + 2));
    int line = 0;

    if (!dest)
        return (NULL);
    for (int x = 0; tab[x]; x++, line++) {
        dest[line] = malloc(sizeof(char) * (my_strlen(tab[x]) + 1));
        if (!dest[line])
            return (NULL);
        dest[line] = tab[x];
        dest[line][my_strlen(tab[x])] = '\0';
    }
    dest[line] = NULL;
    return (dest);
}
