/*
** EPITECH PROJECT, 2018
** Error for cd builtins 42sh
** File description:
** handle error for cd
*/

#include <stdio.h>
#include "my.h"

void my_cd_error(char *str, int ret)
{
    if (ret == -1) {
        my_putstr("\033[0;31m");
        my_putstr(str);
        my_putstr(": ");
        my_putstr(strerror(errno));
        my_putstr(".\n\033[0m");
    }
}