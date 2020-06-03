/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** repeat.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pipe.h"

int my_scane_repeat_nbr(char *str)
{
    if (str == NULL)
        return (0);
    for (int i = 0; str[i];) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (84);
    }
    return (0);
}

char *my_repeat_add_str(char **array)
{
    char *dest = NULL;

    dest = my_strdup(array[2]);
    if (array[3] != NULL) {
        for (int i = 3; array[i]; i++)
            dest = my_strcat_mini(dest, array[i], ' ');
    }
    return (dest);
}

int my_repeat_err(minishell_t *msh, char **array)
{
    int len = my_len_array(array);

    if (len < 3) {
        my_putstr("repeat: Too few arguments.\n");
        msh->return_value = 1;
        return (1);
    }
    if (my_scane_repeat_nbr(array[1]) != 0) {
        my_putstr("repeat: Badly formed number.\n");
        msh->return_value = 1;
        return (1);
    }
    return (0);
}

int my_repeat(minishell_t *msh, char **array)
{
    int loop_nb = 0;
    char *dest = NULL;
    char **command = NULL;

    if (my_repeat_err(msh, array) == 1)
        return (1);
    loop_nb = atoi(array[1]);
    dest = my_repeat_add_str(array);
    command = my_strtwa2(my_clean_str(dest), ' ');
    for (int rep = 0; rep < loop_nb; rep++) {
        msh->verif = 0;
        all_exec_cmd(msh, dest, command);
    }
    msh->verif = 1;
    my_free_array(command);
    free(dest);
    return (0);
}
