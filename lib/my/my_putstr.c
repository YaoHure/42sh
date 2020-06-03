/*
** EPITECH PROJECT, 2018
** MY_PUTSTR
** File description:
** Yaowanart HURE
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
    return (0);
}
