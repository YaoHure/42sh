/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** env.h
*/

#ifndef ENV_H_
#define ENV_H_

//check_set.c
char **replace_line(char **envp, char **new_line, int i);
char **add_new_line(char **envp, char **new_line);
char **check_existing(char **envp, char **new_line);
char **check_setenv(char *buffer, char **envp);
int print_env(minishell_t *msh, char **array);

//my_setenv.c
int my_setenv(minishell_t *msh, char **array);
int my_len_array(char **array);

//unsetenv.c
char **remove_line(char **envp, int arg);
char **search_env(char **envp, char **new_line, int arg);
int my_unsetenv(minishell_t *msh, char **array);
int my_where(minishell_t *msh, char **array);

#endif
