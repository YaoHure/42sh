/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** main.c run all the 42sh
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

int main(int ac, __attribute__((unused))char **av, char **envp)
{
    if (ac == 1) {
        my_take(envp);
    }
}