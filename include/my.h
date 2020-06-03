/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include <dirent.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include "my_struct.h"

int my_repeat(minishell_t *msh, char **array);
char **my_separ_and(char *str);
char **my_separ_or(char *str);
void alias_check(minishell_t *msh, char **command, char *str);
void write_file(minishell_t *msh, char *buff);
int aliases(minishell_t *mysh, char **array);
void my_loop(minishell_t *msh);
void my_exec(minishell_t *msh, char **command);
int help(minishell_t *msh, char **command);
int my_builtins(minishell_t *msh, char **array);
int my_take(char **envp);

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat_mini(char *str, char *lig, char sep);
char *my_strcat(char *str1, char *str2);
void my_put_nbr(int nb);
char *my_itoa(int nb);
int my_first_int_len(int res);
char **my_str_to_word_tab(char *str, char c);
char **wordtab(char **tab, char *str, char c, int nb);
char *my_strndup(char *str, int n);
int my_strncmp(char *s1, char *s2, int nb);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_clean_str(char *str);
int my_str_isalpha(char *str);
int my_str_isnum(char *str);
char **dupli_array(char **env);
char **my_free_array(char **map);
int scane_str(char *str, char c);
char **my_dup_one_more(char **tab);
char **my_dup_tab(char **tab);
int get_nb_tab_line(char **array);
int my_little_len(char *str, int cnt, int *space, char sep);
int cntspace(char *str, char sep);
char **mallocdouble(char *str, char separator);
int my_cword(char *str, char separator);
char **my_strtwa2(char *str, char separator);
char **malloc_fill_arr(char *str, int cnt, char sep, int mem);
char **fill_arr(char *str, char **arr, int cnt, char sep);
char **my_strtwa(char *str, char sep);
int my_scane_str(char *str, char c);
int my_len_array(char **array);
int my_find_char(char *str, char c);

#endif
