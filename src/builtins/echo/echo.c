/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** echo.c : basic echo
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <getopt.h>
#include "sh.h"
#include "my.h"
#include "env.h"
#include "echo.h"

void my_echo_print_quote(char *string)
{
    for (int j = 0; string[j] != '\0'; j++) {
        if (string[j] == '\\' && string[j + 1] != '\0') {
            my_echo_backslash_one(string, j);
            my_echo_backslash_two(string, j);
            j++;
            continue;
        } else if (string[j] == '\"')
            continue;
        my_putchar(string[j]);
    }
}

int my_putstr_echo(minishell_t *msh, char *string)
{
    int state = 0;

    if (my_echo_return_value(string) == 1) {
        my_put_nbr(msh->return_value);
        state = 1;
    }
    for (int i = 0; string[i] != '\0' && state == 0; i++) {
        if (string[i] == '\"') {
            my_echo_print_quote(string);
            break;
        } else if (string[i] == '\\') {
            continue;
        } else
            my_putchar(string[i]);
    }
    return (0);
}

int my_echo_return_value(char *string)
{
    if (my_strcmp(string, "$?") == 1) {
        return (1);
    }
    return (0);
}

int my_echo_check_all(minishell_t *msh, char **array)
{
    int echo_arg = 0;
    int state = 0;

    echo_arg = my_echo_flags(array);
    state = my_echo_check_quotes(array);
    if (state == 0)
        my_echo_check_string(msh, array);
    if (echo_arg == 0) {
        my_putchar('\n');
    }
    return (state);
}

int my_echo(minishell_t *msh, char **array)
{
    int state = 0;

    if (array[1] == NULL) {
        my_putchar('\n');
        return (0);
    } else
        state = my_echo_check_all(msh, array);
    return (state);
}