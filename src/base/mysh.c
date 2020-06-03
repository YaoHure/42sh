/*
** EPITECH PROJECT, 2019
** MySH functions for 42sh
** File description:
** path for execution finding and other core functions
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "error.h"
#include "cd.h"
#include "redir.h"
#include "env.h"
#include "sh.h"

char **ls_in_color(minishell_t *msh, char **command)
{
    if (msh->ls_color == 1) {
        if (my_strcmp(command[0], "ls"))
            command = my_ls_color(command);
    }
    return (command);
}

void my_exec(minishell_t *msh, char **command)
{
    pid_t child;
    child = fork();

    if (child == 0) {
        command = ls_in_color(msh, command);
        if (execvp(command[0], command) == -1) {
            my_cmd_error(command[0]);
        }
        exit (0);
    }
    waitpid(child, &msh->return_value, 0);
    my_sig_cmd(msh->return_value);
}
