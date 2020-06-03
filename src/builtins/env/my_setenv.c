/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_setenv.c manage the function setenv
*/

#include <stdlib.h>
#include <stddef.h>
#include "sh.h"
#include "my.h"
#include "env.h"

char **my_create_new_env(char **env, char *str)
{
    int nb_line = my_len_array(env);
    int len = 0;
    char **new_array = malloc(sizeof(char *) * (nb_line + 2));

    if (new_array == NULL)
        return (NULL);
    for (int i = 0; env[i]; i++, len++)
        new_array[len] = my_strdup(env[i]);
    new_array[len] = my_strdup(str);
    len++;
    new_array[len] = NULL;
    return (new_array);
}

int change_setenv_variable(char **env, char *str, char *str2)
{
    int i = 0;
    char **arg_line;

    for (int y = 0; env[y]; y++) {
        arg_line = my_str_to_word_tab(env[y], '=');
        if (my_strcmp(arg_line[0], str)) {
            if (str2 == NULL)
                env[y] = my_strcat(str, "=");
            else
                env[y] = my_strcat(my_strcat(str, "="), str2);
            i = 1;
            break;
        }
        my_free_array(arg_line);
    }
    return (i);
}

char **change_setenv(char **env, char *str, char *str2)
{
    char *dest = NULL;

    if (change_setenv_variable(env, str, str2) == 1)
        return (env);
    if (str2 == NULL)
        dest = my_strcat(str, "=");
    else
        dest = my_strcat_mini(str, str2, '=');
    env = my_create_new_env(env, dest);
    free(dest);
    return (env);
}

int my_setenv_err(char *str)
{
    if (str == NULL)
        return (0);
    for (int i = 0; str[i];) {
        if ((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z'))
            i++;
        else
            return (84);
    }
    return (0);
}

int my_setenv(minishell_t *msh, char **array)
{
    int x = 0;

    for (; array[x]; x++);
    if (array[1] == NULL || x < 1)
        print_env(msh, array);
    else if (x < 4) {
        if (my_setenv_err(array[1]) == 84) {
            msh->return_value = 1;
            my_putstr(ENV_ERROR);
            return (84);
        }
        else
            msh->env = change_setenv(msh->env, array[1], array[2]);
    } else {
        msh->return_value = 1;
        my_putstr("\033[0;31m");
        my_putstr("setenv: Too many arguments.\n");
        my_putstr("\033[0m");
    }
    return (0);
}