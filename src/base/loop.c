/*
** EPITECH PROJECT, 2019
** Main functions for 42sh
** File description:
** loop functions with getline and functions calls
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"
#include "error.h"
#include "pipe.h"
#include "sh.h"
#include "exit.h"

void my_noob(minishell_t *msh, char **command, char *str)
{
    if (my_strcmp(my_clean_str(str), "le ls en couleur stp")) {
        msh->ls_color = 1;
        return ;
    }
    all_exec_cmd(msh, str, command);
    msh->verif = 0;
}

void my_loop_exec(minishell_t *msh, char *str)
{
    char **command = NULL;
    char **arr = NULL;
    char **ret = my_separ_and(str);

    if (ret == NULL)
        return ;
    for (int i = 0; ret[i]; i++) {
        arr = my_separ_or(ret[i]);
        if (arr == NULL)
            return ;
        for (int i = 0; arr[i]; i++) {
            command = my_strtwa2(my_clean_str(arr[i]), ' ');
            my_noob(msh, command, arr[i]);
            if (msh->return_value == 0)
                break;
            command = my_free_array(command);
        }
    }
}

int my_scane_output(char *str)
{
    char **all_line = my_strtwa2(my_clean_str(str), ';');

    for (int i = 0; all_line[i]; i++) {
        if ((my_separ_and(all_line[i]) == NULL) ||
        (my_separ_or(all_line[i]) == NULL))
            return (1);
    }
    my_free_array(all_line);
    return (0);
}

void my_loop(minishell_t *msh)
{
    char *lineptr = NULL;
    char **all_line = NULL;
    size_t n;

    while (1) {
        my_prompt(msh, isatty(STDIN_FILENO), msh->env);
        my_signal();
        if (getline(&lineptr, &n, stdin) == -1) {
            my_print_exit();
            free(msh);
            exit (0);
        }
        lineptr[my_strlen(lineptr) - 1] = '\0';
        if (my_scane_output(lineptr) == 0) {
            all_line = my_strtwa2(my_clean_str(lineptr), ';');
            for (int a = 0; all_line[a]; a++)
                my_loop_exec(msh, all_line[a]);
            all_line = my_free_array(all_line);
        }
    }
}

int my_take(char **envp)
{
    minishell_t *msh = malloc(sizeof(minishell_t));

    if (msh == NULL) {
        my_putstr("Failed to malloc struct.\n");
        exit (84);
    }
    msh->ls_color = 0;
    msh->my_old_dir = "ici";
    msh->verif = 0;
    msh->env = my_dup_tab(envp);
    msh->return_value = 0;
    my_loop(msh);
    putchar('\n');
    exit (msh->return_value);
}
