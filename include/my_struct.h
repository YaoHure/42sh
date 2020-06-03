/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_
#include <stdio.h>

typedef struct minishell_s {
    char *my_old_dir;
    char **env;
    char *hist_dir;
    char *alias_dir;
    FILE *fp;
    FILE *fd;
    int verif;
    int nothing;
    int return_value;
    int ls_color;
} minishell_t;

#endif
