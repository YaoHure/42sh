/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "./../../include/my.h"

int my_len_array(char **array)
{
    int len = 0;

    for (len = 0; array[len]; len++);
    return (len);
}
