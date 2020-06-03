/*
** EPITECH PROJECT, 2019
** by Quentin Lavieville
** File description:
** my_strtwa
*/

#include "../../include/my.h"

int my_little_len(char *str, int cnt, int *space, char sep)
{
    while (str[cnt] != sep && str[cnt] != '\0' && str[cnt] != '\t') {
        cnt++;
    }
    *(space) += 1;
    return (cnt);
}

int cntspace(char *str, char sep)
{
    int cnt = 0;
    int space = 0;

    while (str[cnt] != '\0') {
        if (str[cnt] == sep || str[cnt] == '\t')
            space++;
        cnt++;
    }
    space++;
    return (space);
}
