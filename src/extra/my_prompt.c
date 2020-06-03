/*
** EPITECH PROJECT, 2018
** DUPROS Leegan
** File description:
** my_prompt.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"
#include "sh.h"

char **change_my_pwd(char **env, char *str)
{
    char *buff = getcwd(NULL, 0);

    for (int y = 0; env[y]; y++) {
        if (my_strncmp(env[y], str, my_strlen(str))) {
            env[y] = my_strcat(str, buff);
            break;
        }
    }
    return (env);
}

char *find_my_pwd(char **env)
{
    char *dest;
    char **arg_line;

    for (int y = 0; env[y]; y++) {
        if (my_strncmp(env[y], "PWD=", 4)) {
            arg_line = my_str_to_word_tab(env[y], '=');
            dest = my_strdup(arg_line[1]);
            break;
        }
    }
    my_free_array(arg_line);
    return (dest);
}

void my_prompt_arrow(minishell_t *msh)
{
    my_promp_check_git();
    my_print_time();
    if (msh->return_value == 0) {
        my_putstr("\033[1;32m");
        my_putstr(" $> ");
        my_putstr("\033[0m");
    } else {
        my_putstr("\033[1;31m");
        my_putstr(" $> ");
        my_putstr("\033[0m");
    }
}

void my_prompt_gen(char *str)
{
    my_putstr("\033[1;36m");
    my_putstr(str);
    my_putstr("\033[0m");
}

void my_prompt(minishell_t *msh, int i, char **env)
{
    int x = 0;
    env = change_my_pwd(env, "PWD=");
    char **my_pwd;

    if (i == 1) {
        if (my_strcmp(getcwd(NULL, 0), "/")) {
            my_prompt_gen("/");
            my_prompt_arrow(msh);
            return ;
        }
        my_pwd = my_str_to_word_tab(getcwd(NULL, 0), '/');
        for (x = 0; my_pwd[x] != NULL; x++);
        my_prompt_gen(my_pwd[x - 1]);
        my_prompt_arrow(msh);
        my_free_array(my_pwd);
    }
}