/*
** EPITECH PROJECT, 2018
** DUPROS Leegan
** File description:
** my_signal.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stddef.h>
#include "error.h"
#include "my.h"
#include "sh.h"

void my_control_c(int c)
{
    char **my_pwd;
    (void)c;
    int x = 0;

    if (my_strcmp(getcwd(NULL, 0), "/")) {
        my_putchar('\n');
        my_prompt_gen("/");
        my_putstr("\033[1;32m");
        my_putstr(" $> ");
        my_putstr("\033[0m");
        return ;
    }
    my_pwd = my_str_to_word_tab(getcwd(NULL, 0), '/');
    for (x = 0; my_pwd[x] != NULL; x++);
    my_putchar('\n');
    my_prompt_gen(my_pwd[x - 1]);
    my_putstr("\033[1;32m");
    my_putstr(" $> ");
    my_putstr("\033[0m");
    my_free_array(my_pwd);
}

int my_signal(void)
{
    if (signal(SIGINT, my_control_c) == SIG_ERR) {
        my_putstr("error: signal.\n");
        return (0);
    }
    return (1);
}

void my_sig_cmd(int stat)
{
    int signal;

    if (WIFSIGNALED(stat)) {
        signal = WTERMSIG(stat);
        if (signal == SIGSEGV)
            write(2, "Segmentation fault\n", 19);
        else if (signal == SIGFPE)
            write(2, "Floating exception\n", 19);
    }
}