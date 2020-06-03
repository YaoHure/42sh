/*
** EPITECH PROJECT, 2018
** Error function for Binary 42sh
** File description:
** Handle error for binaries
*/

#include <stdio.h>
#include "my.h"

void use_bin_exec_error(char *str)
{
    my_putstr("\033[0;31m");
    perror(str);
    my_putstr("\033[0m");
}