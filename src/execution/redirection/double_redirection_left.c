/*
** EPITECH PROJECT, 2018
** Double redir left 42sh
** File description:
** Execute 42sh redir left functions
*/

#include <stdlib.h>
#include "my.h"
#include "pipe.h"

void redirection_left_two(minishell_t *msh, char **cmd)
{
    size_t n;
    char *my_line = NULL;
    char **command = NULL;

    my_putstr("? ");
    while (getline(&my_line, &n, stdin) != -1){
        my_line[my_strlen(my_line) - 1] = '\0';
        if (my_strcmp(my_line, my_clean_str(cmd[1])))
            break;
        my_putstr("? ");
    }
    msh->return_value = 0;
    command = my_strtwa2(my_clean_str(cmd[0]), ' ');
    all_exec_cmd(msh, my_clean_str(cmd[0]), command);
    my_free_array(command);
}