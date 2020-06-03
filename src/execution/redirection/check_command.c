/*
** EPITECH PROJECT, 2018
** Redir checker 42sh
** File description:
** checking existing command
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "redir.h"

int verif_command(char **path, char *str)
{
    char **cmd = my_str_to_word_tab(my_clean_str(str), ' ');

    char *dest = get_path(path, cmd[0]);
    if (dest == NULL) {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
        free(dest);
        my_free_array(cmd);
        return (0);
    }
    return (1);
}