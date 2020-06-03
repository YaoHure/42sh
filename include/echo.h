/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** echo.h
*/

#ifndef ECHO_H_
#define ECHO_H_

#include "my_struct.h"

//echo_check.c
int my_echo_check_quotes(char **array);
void my_echo_backslash_one(char *string, int i);
void my_echo_backslash_two(char *string, int i);
void my_echo_check_string(minishell_t *msh, char **array);
int my_echo_flags(char **array);

//echo.c
int my_echo(minishell_t *msh, char **array);
int my_putstr_echo(minishell_t *msh, char *string);
void my_echo_print_quote(char *string);
int my_echo_return_value(char *string);
int my_echo_check_all(minishell_t *msh, char **array);

#endif
