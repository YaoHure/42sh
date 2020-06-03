/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my_strndup.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_strndup(char *str, int n)
{
    char *new_str;
    int i;

    i = 0;
    new_str = malloc(my_strlen(str) + 1);
    while (str[i] && i < n) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = 0;
    return (new_str);
}
