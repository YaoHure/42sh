/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_cd_cmd.c : exec cd basic with flags
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "cd.h"
#include "my.h"
#include "error.h"

void my_cd_cmd_without_arg(char **env)
{
    char *dest = NULL;
    char **arg_line;

    for (int y = 0; env[y]; y++) {
        if (my_strncmp(env[y], "HOME=", 5)) {
            arg_line = my_str_to_word_tab(env[y], '=');
            dest = my_strdup(arg_line[1]);
            break;
        }
    }
    if (dest != NULL) {
        chdir(dest);
        free(dest);
        arg_line = my_free_array(arg_line);
    }
}

int my_cd_cmd_with_arg(char **env, char **array, minishell_t *msh)
{
    char *dest;
    int ret = 0;

    if (my_strcmp(array[1], "-") || my_strcmp(array[1], "-1")) {
        dest = getcwd(NULL, 0);
        ret = chdir(msh->my_old_dir);
        msh->my_old_dir = dest;
    } else if (my_strcmp(array[1], "~")) {
        msh->my_old_dir = getcwd(NULL, 0);
        my_cd_cmd_without_arg(env);
        ret = 1;
    } else {
        msh->my_old_dir = getcwd(NULL, 0);
        ret = chdir(array[1]);
    }
    return (ret);
}

int my_cd_cmd(minishell_t *msh, char **array)
{
    int x = 0;
    int ret = 0;

    for (; array[x]; x++);
    if (x == 2) {
        ret = my_cd_cmd_with_arg(msh->env, array, msh);
        my_cd_error(array[1], ret);
        if (ret == -1)
            return (1);
    } else {
        msh->my_old_dir = getcwd(NULL, 0);
        my_cd_cmd_without_arg(msh->env);
    }
    return (0);
}
