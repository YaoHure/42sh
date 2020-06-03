/*
** EPITECH PROJECT, 2018
** Redirection Right 42sh
** File description:
** functions for redirection right
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

void exec_redirection(int fdop, int *fd)
{
    char *buffer = malloc(sizeof(char) * 20);
    char dest[20];
    int size = 19;

    if (buffer == NULL)
        return ;
    wait(NULL);
    close(fd[1]);
    buffer[0] = '\0';
    while (size == 19 && size != 0) {
        size = read(fd[0], dest, 19);
        dest[size] = '\0';
        buffer = my_strcat(buffer, dest);
    }
    write(fdop, buffer, my_strlen(buffer));
    free(buffer);
    close(fdop);
}

int check_command(char *str, int *fd, int fdop)
{
    int ret = 0;
    char **array2 = NULL;

    dup2(fd[1], 1);
    close(fd[0]);
    array2 = my_strtwa2(my_clean_str(str), ' ');
    if (execvp(array2[0], array2) == -1) {
        close(fdop);
        ret = 1;
        write(2, array2[0], strlen(array2[0]));
        write(2, ": Command not found.\n", 21);
        my_free_array(array2);
        exit (0);
    }
    if (strerror(errno) != NULL)
        ret = 1;
    my_free_array(array2);
    return (ret);
}

void redir_right_without_builtins(char *cmd, int fdop)
{
    int fd[2] = {0};
    int ret = 0;

    if (pipe(fd) == -1) {
        perror("error pipe\n");
        exit(1);
    }
    if (fork() == 0)  {
        ret = check_command(cmd, fd, fdop);
    }
    else if (ret == 0)
        exec_redirection(fdop, fd);
    close(fd[1]);
}

int redirection_right(minishell_t *msh, char *cmd, int i)
{
    int fdop = 0;
    char **tab = NULL;
    char **array = my_strtwa2(my_clean_str(cmd), '>');

    if (scane_redir_right(my_clean_str(cmd)) == 1) {
        my_putstr("Missing name for redirect.\n");
        msh->return_value = 1;
        return (84);
    }
    fdop = create_file(array[1], i);
    tab = my_strtwa2(my_clean_str(array[0]), ' ');
    if ((my_strcmp(tab[0], "env")) || (my_builtins(msh, tab) == 0))
        redir_right_without_builtins(array[0], fdop);
    my_free_array(array);
    return (0);
}