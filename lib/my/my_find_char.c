/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_find_char.c
*/

int my_find_char(char *str, char c)
{
    int pos = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] == c) && (i > pos))
            pos = i;
    }
    return (pos);
}
