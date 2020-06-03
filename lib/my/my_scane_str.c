/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** my_scane_str.c
*/

int my_scane_str(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}
