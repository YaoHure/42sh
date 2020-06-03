/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** 42sh.h
*/

#ifndef SH_H_
#define SH_H_

#include "my_struct.h"

#define ENV_ERROR "setenv: Variable name must contain \
alphanumeric characters.\n"\
//my_prompt.c
char **change_my_pwd(char **env, char *str);
char *find_my_pwd(char **env);
void my_prompt(minishell_t *msh, int i, char **env);
void my_prompt_gen(char *str);
void my_prompt_arrow(minishell_t *msh);
int my_promp_check_git(void);
int find_git_branch(char *string);
int read_and_print_git(int filesize, int fd);
int get_git_branch(char *buffer);
int my_print_time(void);
char **my_ls_color(char **array);

#endif
