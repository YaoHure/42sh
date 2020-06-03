/*
** EPITECH PROJECT, 2018
** CPE_lemin_2018
** File description:
** my_str_isnum.c
*/

int my_str_isalpha(char *str)
{
    int i = 0;
    while (str[i] != 0) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z'))
        i = i + 1;
        else
            return (84);
    }
    return (0);
}
