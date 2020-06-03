/*
** EPITECH PROJECT, 2018
** DUPROS Leegan
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + str[i] - 48;
    }
    if (str[0] == '-')
        nb = nb * (-1);
    return (nb);
}
