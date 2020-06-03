/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** builtins.h init the functions pointers struct
*/

#ifndef BUILTINS_H_
#define BUILTINS_H_
#include "my.h"
#include "my_struct.h"

struct  built_s
{
    char *name;
    int (*fnc)(minishell_t *, char **);
};

typedef struct built_s built_t;

built_t built_tab[] =
{
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"env", &print_env},
    {"cd", &my_cd_cmd},
    {"echo", &my_echo},
    {"where", &my_where},
    {"exit", &my_exit},
    {"repeat", &my_repeat},
    {NULL, NULL}
};

extern  built_t built_tab[];

#endif
