/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** str_to_word_tab.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

char **wordtab(char **tab, char *str, char c, int nb)
{
    int i = 0;
    int j = 0;
    int loop = 1;

    while (str[i] != '\0') {
        while (str[i] != '\0' && str[i] != c) {
            i++;
            j++;
            loop = 0;
        }
        if (!loop) {
            tab[nb] = my_strndup(str + i - j, j);
            nb++;
            j = 0;
        }
        while (str[i] == c && str[i] && i++);
    }
    tab[nb] = NULL;
    return (tab);
}

char **my_str_to_word_tab(char *str, char c)
{
    int i = 0;
    int loop = 0;
    int nb = 0;
    char **tab;

    while (str[i] != '\0') {
        if (str[i] != c && loop == 0) {
            nb++;
            loop = 1;
        }
        else if (str[i] == c)
        loop = 0;
    i++;
    }
    tab = malloc(sizeof(char *) * (nb + 1));
    if (tab == NULL)
        return (NULL);
    tab = wordtab(tab, str, c, 0);
    return (tab);
}
