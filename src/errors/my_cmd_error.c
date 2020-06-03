/*
** EPITECH PROJECT, 2018
** Most of commands error messages 42sh
** File description:
** Functions for error.
*/

#include "my.h"

int my_cmd_error(char *cmd)
{
    char *msg = strerror(errno);

    if (errno == ENOEXEC) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
        return (0);
    }
    my_putstr(cmd);
    my_putstr(": ");
    if (my_strcmp(msg, "No such file or directory"))
        my_putstr("Command not found.\n");
    else {
        my_putstr(msg);
        my_putstr(".\n");
    }
    return (0);
}

int my_error_permission(char *cmd)
{
    my_putstr(cmd);
    my_putstr(": Command not found.\n");
    return (0);
}

int my_redir_left_error(char *str, int ret)
{
    my_putstr(str);
    return (ret);
}