/*
** EPITECH PROJECT, 2019
** Where command .c
** File description:
** Where command, tells you where a command is
*/

#include "my.h"
#include "error.h"
#include "sh.h"
#include "my_struct.h"
#include "cd.h"
#include "redir.h"
#include "env.h"
#include "echo.h"

int try_command_before(char *buf)
{
    if ((access(buf, F_OK | X_OK) == 0) || (buf != NULL &&
        buf[0] == '.' && buf[1] == '/'))
        return (1);
    return (0);
}

char *find_cmd_path(char **command_path, char *buffer, char *cmd)
{
    int i = 0;
    char **buf = my_strtwa(buffer, ' ');

    if (try_command_before(buf[0]) == 1)
        return (buf[0]);
    for (; command_path[i] != NULL; i++) {
        cmd = my_strcat_mini(command_path[i], buf[0], '/');
        if (access(cmd, F_OK | X_OK) == 0) {
            buf = my_free_array(buf);
            return (cmd);
        }
    }
    if (command_path[i] == NULL)
        return (NULL);
    buf = my_free_array(buf);
    return (cmd);
}

char *where_is_cmd(char *buffer, char **envp, int i)
{
    char **actual_line = NULL;
    char *cmd = NULL;
    char **command_path = NULL;

    actual_line = my_strtwa(envp[i], '=');
    while (envp[i] != NULL && (my_strcmp(actual_line[0], "PATH") != 1)) {
        actual_line = my_free_array(actual_line);
        i++;
        actual_line = my_strtwa(envp[i], '=');
        if (envp[i] == NULL)
            actual_line = NULL;
    }
    if (actual_line != NULL) {
        command_path = my_strtwa(actual_line[1], ':');
        actual_line = my_free_array(actual_line);
        cmd = find_cmd_path(command_path, buffer, cmd);
    }
    if (cmd == NULL)
        return (NULL);
    return (cmd);
}

int my_where(minishell_t *msh, char **array)
{
    char *cmd = NULL;
    int i = 1;

    while (array[i] != NULL) {
        cmd = where_is_cmd(array[i], msh->env, 0);
        if (cmd != NULL)
            printf("%s: shell built-in command\n%s\n", array[i], cmd);
        i++;
    }
    return (0);
}