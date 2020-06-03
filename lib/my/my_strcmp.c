/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_strcmp.c
*/

int my_strlen_bis(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_strcmp(char const *str1, char const *str2)
{
    if (my_strlen_bis(str1) != my_strlen_bis(str2))
        return (0);
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}
