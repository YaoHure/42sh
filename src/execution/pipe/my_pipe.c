/*
** EPITECH PROJECT, 2018
** Catching pipes in input for 42sh
** File description:
** Handle pipe commands
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "pipe.h"
#include "redir.h"
#include "error.h"

int my_pipe_verifi(char **env, char *str)
{
    char **cmd = my_str_to_word_tab(my_clean_str(str), ' ');

    char *dest = get_path(env, cmd[0]);
    if (dest == NULL) {
        my_cmd_error(cmd[0]);
        free(dest);
        my_free_array(cmd);
        return (0);
    }
    return (1);
}

int scane_pipe(char *str)
{
    int position = my_find_char(str, '|');

    if (strcspn(str, "|") == 0)
        return (1);
    if ((position == 0) || ((position + 1) == my_strlen(str)))
        return (1);
    return (0);
}

int the_pipe(minishell_t *msh, char *str)
{
    char **array = my_str_to_word_tab(my_clean_str(str), '|');

    if (scane_pipe(my_clean_str(str)) == 1) {
        my_putstr("Invalid null command.\n");
        msh->return_value = 1;
        return (84);
    }
    multiple_pipe(msh, array);
    return (0);
}