/*
** EPITECH PROJECT, 2018
** Executing all commands execpt builtins 42sh
** File description:
** functions for commands executions
*/

#include "my.h"
#include "pipe.h"
#include "redir.h"
#include "my_struct.h"

void all_exec_cmd(minishell_t *msh, char *str, char **command)
{
    int ret = 0;

    if ((my_scane_str(str, '|') >= 1))
        the_pipe(msh, str);
    else if ((ret = my_scane_str(str, '>')))
        redirection_right(msh, str, ret);
    else if ((ret = my_scane_str(str, '<')))
        redirection_left(msh, str, ret);
    else {
        my_builtins(msh, command);
        if (msh->verif == 0)
            my_exec(msh, command);
    }
}