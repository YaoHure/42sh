/*
** EPITECH PROJECT, 2019
** by Quentin Lavieville
** File description:
** transform a string into a double array
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

int my_cword(char *str, char separator)
{
    int w = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] != separator) {
            w++;
            for (; str[i] != separator && str[i]; i++);
        }
    }
    return (w);
}

char **mallocdouble(char *str, char separator)
{
    int w = 0;
    unsigned long j = 0;
    int len = my_strlen(str);
    char **array = NULL;

    array = malloc(sizeof(char *) * ((unsigned long)
    my_cword(str, separator) + 1));
    if (!array) {
        return (NULL);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != separator) {
            for (j = 0; str[i] != separator && i < len; i++, j++);
            array[w] = malloc(sizeof(char) * (j + 1));
            w++;
        }
    }
    return (array);
}

char **my_strtwa2(char *str, char separator)
{
    char **array = NULL;
    int w = 0;
    int j = 0;
    int x = 0;
    int start = 0;
    int len = my_strlen(str);

    array = mallocdouble(str, separator);
    for (int i = 0; array && i < len; i++) {
        if (str[i] != separator) {
            start = i;
            for (j = 0; str[i] != separator && i < len; i++, j++);
            for (x = 0; start < i; x++, start++)
                array[w][x] = str[start];
            array[w][x] = '\0';
            w++;
        }
    }
    array[w] = NULL;
    return (array);
}
