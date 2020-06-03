/*
** EPITECH PROJECT, 2018
** Simple Redir Left 42sh
** File description:
** functions for simple redir left
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "my.h"
#include "redir.h"
#include "error.h"
#include "pipe.h"

int scane_redir_left(char *str)
{
    int position = my_find_char(str, '<');

    if ((strcspn(str, "<") == 0) || (my_scane_redir_nbr(str, "<<<") == 1))
        return (1);
    if ((position == 0) || ((position + 1) == my_strlen(str)))
        return (1);
    return (0);
}

int redirection_left_one(minishell_t *msh, char **cmd)
{
    int fd = 0;
    int fd_tmp = 0;
    char **cmd_exec = NULL;

    fd = open(my_clean_str(cmd[1]), O_RDONLY);
    if (fd == - 1) {
        msh->return_value = 1;
        my_putstr(my_clean_str(cmd[1]));
        return (my_redir_left_error(": No such file or directory.\n", -1));
    }
    fd_tmp = dup(0);
    if ((fd_tmp == -1) || (dup2(fd, 0) == -1))
        return (-1);
    cmd_exec = my_strtwa2(my_clean_str(cmd[0]), ' ');
    all_exec_cmd(msh, my_clean_str(cmd[0]), cmd_exec);
    if (dup2(fd_tmp, 0) == -1)
        return (-1);
    close(fd);
    close(fd_tmp);
    return (0);
}

int redirection_left(minishell_t *msh, char *str, int i)
{
    char **cmd = my_strtwa2(my_clean_str(str), '<');

    if (scane_redir_left(my_clean_str(str)) == 1) {
        my_putstr("Missing name for redirect.\n");
        msh->return_value = 1;
        return (84);
    } else {
        if (i == 1)
            redirection_left_one(msh, cmd);
        else if (i == 2)
            redirection_left_two(msh, cmd);
    }
    return (0);
}