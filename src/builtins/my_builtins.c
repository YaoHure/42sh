/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_builtins.c set the struct of function pointers
*/

#include <stdlib.h>
#include "my.h"
#include "error.h"
#include "sh.h"
#include "my_struct.h"
#include "cd.h"
#include "env.h"
#include "echo.h"
#include "exit.h"
#include "builtins.h"

int my_builtins(minishell_t *msh, char **array)
{
    int i = 0;
    int ret = 0;

    for (i = 0; built_tab[i].name; i++) {
        if (my_strcmp(built_tab[i].name, array[0])) {
            msh->verif = 1;
            msh->return_value = built_tab[i].fnc(msh, array);
            ret = 1;
            break;
        }
    }
    return (ret);
}