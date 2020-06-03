/*
** EPITECH PROJECT, 2018
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdlib.h>

char **my_free_array(char **map)
{
    int i = 0;
    int line;

    for (line = 0; map[line]; line++);
    for (; i != line; i++)
        free(map[i]);
    free(map);
    return (map);
}
