/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** pipe.h
*/

#ifndef PIPE_H_
#define PIPE_H_

//my_pipe_execution.c
void my_pipe_exec_1(char *str, int *fd);
void my_pipe_exec_2(char *str, int *fd);

//my_pipe.c

int my_pipe(char **array);
int my_pipe_verifi(char **env, char *str);
int the_pipe(minishell_t *msh, char *str);

void all_exec_cmd(minishell_t *msh, char *str, char **command);

//multiple_pipe.c
void multiple_pipe(minishell_t *msh, char **cmd);

#endif
