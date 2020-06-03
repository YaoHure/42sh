/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** unsetenv.c manage the function unsetenv
*/

#include <stddef.h>
#include "my.h"
#include "env.h"

char **remove_line(char **envp, int arg)
{
    int j = 0;
    int i = 0;

    for (; envp[i] != NULL; i++) {
        if (j == arg)
            j++;
        envp[i] = envp[j];
        j++;
    }
    envp[i] = NULL;
    return (envp);
}

char **search_env(char **envp, char **new_line, int arg)
{
    int i = 0;
    char **actual_line = NULL;

    actual_line = my_strtwa(envp[i], '=');
    while (envp[i] != NULL &&
        (my_strcmp(actual_line[0], new_line[arg]) != 1)) {
        actual_line = my_free_array(actual_line);
        i++;
        actual_line = my_strtwa(envp[i], '=');
        if (envp[i] == NULL)
            actual_line = NULL;
    }
    if (envp[i] != NULL && (my_strcmp(actual_line[0], new_line[arg]) == 1))
        envp = remove_line(envp, i);
    return (envp);
}

int my_unsetenv(minishell_t *msh, char **new_line)
{
    int arg = 1;

    if (new_line[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (1);
    }
    while (new_line[arg] != NULL) {
        msh->env = search_env(msh->env, new_line, arg);
        arg++;
    }
    return (0);
}