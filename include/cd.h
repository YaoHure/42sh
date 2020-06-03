/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** cd.h
*/

#ifndef CD_H_
#define CD_H_

#include "my_struct.h"

//my_cd_cmd.c
void my_cd_cmd_without_arg(char **env);
int my_cd_cmd_with_arg(char **env, char **array, minishell_t *msh);
int my_cd_cmd(minishell_t *msh, char **array);

#endif
