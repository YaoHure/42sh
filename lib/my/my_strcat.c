/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** my_strcat.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *str, char *str2)
{
    int k = my_strlen(str) + my_strlen(str2);
    char *res  = malloc(sizeof(char) * (k + 1));
    int i = 0;
    int a = 0;

    while (str[i] != '\0') {
        res[a] = str[i];
        i++;
        a++;
    }
    i = 0;
    while (str2[i]) {
        res[a] = str2[i];
        a++;
        i++;
    }
    res[k] = '\0';
    return (res);
}
