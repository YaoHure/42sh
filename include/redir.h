/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** redir.h
*/

#ifndef REDIR_H_
#define REDIR_H_

#include "my_struct.h"

int my_scane_redir_nbr(char *str, char *ref);

//check_command.c
int verif_command(char **path, char *str);

//get_path.c
char *get_path(char **tab, char *comd);
char *my_getenv(char **env, char *str);

//redirection_left.c
void check_command2(char **path, char **env, char *str, int *fd);
void exec_redirection_left(int status, char *str, int *fd, int i);
int redirection_left(minishell_t *msh, char *str, int i);
int redirection_left_one(minishell_t *msh, char **cmd);
void redirection_left_two(minishell_t *msh, char **cmd);

//redirection_right.c
void exec_redirection(int fdop, int *fd);
int check_command(char *str, int *fd, int fdop);
int check_redirection(char **env, char **array);
int redirection_right(minishell_t *msh, char *cmd, int i);

int my_scane_redir_nbr(char *str, char *ref);
int scane_redir_right(char *str);
int create_file(char *str, int i);
#endif
