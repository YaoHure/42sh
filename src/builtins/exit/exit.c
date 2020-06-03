/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** exit.c manage the exit basic and also with the return value
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "sh.h"
#include "my.h"
#include "env.h"
#include "echo.h"
#include "exit.h"

void my_exit_atoi(char *string)
{
    if (my_strcmp(string, "0") == 1) {
        my_print_exit();
        exit (0);
    } else if (atoi(string) != 0) {
        my_print_exit();
        exit (atoi(string));
    } else
        my_putstr("exit: Expression Syntax.\n");
}

void my_print_exit(void)
{
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
}

int my_exit(__attribute__((unused))minishell_t *msh, char **array)
{
    if (my_len_array(array) > 2)
        my_putstr("exit: Expression Syntax.\n");
    else if (array[1] != NULL) {
        my_exit_atoi(array[1]);
    } else {
        my_print_exit();
        exit (0);
    }
    return (0);
}
