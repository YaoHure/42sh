/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my_strdup.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char *str)
{
    char *dest = malloc(sizeof(*str) * my_strlen(str) + 1);

    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, str);
    return (dest);
}
