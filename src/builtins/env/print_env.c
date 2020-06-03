/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** print_env.c print the env
*/

#include "my.h"

int print_env(minishell_t *msh, __attribute__((unused))char **array)
{
    for (int i = 0; msh->env[i]; i++) {
        my_putstr(msh->env[i]);
        my_putchar('\n');
    }
    return (0);
}