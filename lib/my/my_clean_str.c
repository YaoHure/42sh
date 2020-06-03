/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** my_clean_str.c
*/

#include <stdlib.h>
#include "../../include/my.h"

int next_word(char *str, int i)
{
    while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        i++;
    return (i);
}

char *mall_clean(char *str)
{
    char *new;
    int len = 0;

    for (int i = next_word(str, 0); str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            i = next_word(str, i);
            len++;
        }
        len++;
        if (str[i] == '\0')
            i--;
    }
    new = malloc(sizeof(char) * len + 1);
    return (new);
}

char *my_clean_str(char *str)
{
    char *new = mall_clean(str);
    int j = 0;

    for (int i = next_word(str, 0); str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\t') &&
        str[next_word(str, i)] == '\0') {
            i = next_word(str, i) - 1;
        } else if (str[i] == ' ' || str[i] == '\t') {
            i = next_word(str, i) - 1;
            new[j] = ' ';
            j++;
        } else {
            new[j] = str[i];
            j++;
        }
    }
    new[j] = '\0';
    return (new);
}
