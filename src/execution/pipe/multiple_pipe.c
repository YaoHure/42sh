/*
** EPITECH PROJECT, 2018
** Multiple pipe functions for 42sh
** File description:
** Handle pipe and multiple pipe
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "my.h"

int my_scan_multiple_pipe_builts(minishell_t *msh, char **cmd)
{
    int len = my_len_array(cmd);
    int pass = 0;
    char *bas[] = {"setenv", "unsetenv", "env", "cd", "echo", "where",
    "exit", "history", "alias", NULL};
    char **tabill = my_str_to_word_tab(my_clean_str(cmd[len-1]), ' ');

    for (int i = 0; bas[i]; i++) {
        if (my_strcmp(bas[i], tabill[0])) {
            pass = 1;
            break;
        }
    } if (pass == 1) {
        for (int a = 0; cmd[a]; a++) {
            char **tab = my_str_to_word_tab(my_clean_str(cmd[a]), ' ');
            msh->verif = 0;
            my_builtins(msh, tab);
        }
        return (1);
    }
    return (0);
}

int multiple_pipe_exec(int fdd, char **cmd, int *fd, int i)
{
    char **array2 = NULL;

    dup2(fdd, 0);
    if (cmd[i + 1] != NULL) {
        dup2(fd[1], 1);
    }
    close(fd[0]);
    array2 = my_str_to_word_tab(my_clean_str(cmd[i]), ' ');
    if (execvp(array2[0], array2) == -1)
        my_cmd_error(array2[0]);
    exit(1);
}

void multiple_pipe(minishell_t *msh, char **cmd)
{
    int fd[2];
    pid_t pid;
    int fdd = 0;

    if (my_scan_multiple_pipe_builts(msh, cmd) == 1)
        return ;
    for (int i = 0; cmd[i] != NULL;) {
        pipe(fd);
        pid = fork();
        if (pid == -1)
            exit(1);
        else if (pid == 0)
            multiple_pipe_exec(fdd, cmd, fd, i);
        else {
            wait(NULL);
            close(fd[1]);
            fdd = fd[0];
            i++;
        }
    }
}