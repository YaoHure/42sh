/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** my_strcat_mini.c
*/

#include <string.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat_mini(char *str, char *lig, char sep)
{
    int k = my_strlen(str) + my_strlen(lig) + 1;
    char *res  = malloc(sizeof(char) * (k + 2));
    int i = 0;
    int a = 0;

    while (str[i] != '\0') {
        res[a] = str[i];
        i++;
        a++;
    }
    i = 0;
    res[a++] = sep;
    while (lig[i]) {
        res[a] = lig[i];
        a++;
        i++;
    }
    res[k] = '\0';
    return (res);
}
