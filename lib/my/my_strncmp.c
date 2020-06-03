/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** my_strncmp.c
*/

/*int my_strncmp(char *s1, char *s2, int nb)
{
    int a = 0;

    while (s1[a] == s2[a] && s1[a] && s2[a] && a < nb) {
        a++;
    }
    if ((s1[a] == '\0' && s2[a] == '\0') || a == nb) {
        return (0);
    }
    else if (s1[a] > s2[a]) {
        return (1);
    }
    else
        return (-1);
}*/

int my_strncmp(char *str, char *str2, int len)
{
    for (int i = 0; i < len; i++) {
        if (str[i] != str2[i])
            return (0);
    }
    return (1);
}
