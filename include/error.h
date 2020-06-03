/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** error.h
*/

#ifndef ERROR_H_
#define ERROR_H_

//bin_exec_error.c
void use_bin_exec_error(char *str);

//my_cd_error.c
void my_cd_error(char *str, int ret);

//my_cmd_error.c
int my_cmd_error(char *cmd);
int my_error_permission(char *cmd);
int my_redir_left_error(char *str, int ret);

//my_signal.c
void my_control_c(int c);
int my_signal(void);
void my_sig_cmd(int stat);

#endif
