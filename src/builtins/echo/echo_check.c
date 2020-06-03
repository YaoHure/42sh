/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** echo_check.c : check the flags of echo
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <getopt.h>
#include "sh.h"
#include "my.h"
#include "env.h"
#include "echo.h"

int my_echo_check_quotes(char **array)
{
    int quotes = 0;

    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == '\"')
                quotes++;
        }
    }
    if ((quotes % 2) == 1) {
        my_putstr("Unmatched '\"'.");
        return (1);
    }
    return (0);
}

void my_echo_backslash_one(char *string, int i)
{
    switch (string[i + 1]) {
        case 'n':
            my_putchar('\n');
            break;
        case 'a':
            my_putchar('\a');
            break;
        case 'b':
            my_putchar('\b');
            break;
        case 'e':
            my_putchar('\e');
            break;
    }
}

void my_echo_backslash_two(char *string, int i)
{
    switch (string[i + 1]) {
        case 'f':
            my_putchar('\f');
            break;
        case 'r':
            my_putchar('\r');
            break;
        case 't':
            my_putchar('\t');
            break;
        case 'v':
            my_putchar('\v');
            break;
    }
}

void my_echo_check_string(minishell_t *msh, char **array)
{
    for (int i = 1; array[i] != NULL; i++) {
        if (i == 1 && my_strcmp(array[i], "-n") == 1) {
            continue;
        }
        my_putstr_echo(msh, array[i]);
        if (array[i + 1] != NULL)
            my_putchar(' ');
    }
}

int my_echo_flags(char **array)
{
    if (my_strcmp(array[1], "-n") == 1) {
        return (1);
    }
    return (0);
}