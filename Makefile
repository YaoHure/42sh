##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for making sources
##

SRC	=	src/main.c							\
		src/base/loop.c							\
		src/base/mysh.c							\
		src/builtins/cd/my_cd_cmd.c					\
		src/builtins/env/my_setenv.c					\
		src/builtins/env/unsetenv.c					\
		src/builtins/env/print_env.c					\
		src/builtins/my_builtins.c					\
		src/builtins/echo/echo.c					\
		src/builtins/echo/echo_check.c					\
		src/builtins/exit/exit.c					\
		src/extra/my_prompt.c						\
		src/extra/my_git.c						\
		src/extra/my_print_time.c					\
		src/extra/my_signal.c						\
		src/extra/my_ls_color.c						\
		src/repeat/my_repeat.c						\
		src/separator/my_separ_and.c					\
		src/separator/my_separ_or.c					\
		src/execution/all_exec_cmd.c					\
		src/execution/pipe/my_pipe.c					\
		src/execution/pipe/multiple_pipe.c				\
		src/execution/redirection/check_command.c			\
		src/execution/redirection/get_path.c				\
		src/execution/redirection/redirection_left.c			\
		src/execution/redirection/double_redirection_left.c		\
		src/execution/redirection/redirection_right.c			\
		src/execution/redirection/my_redir_tools.c			\
		src/errors/bin_exec_error.c					\
		src/errors/my_cd_error.c					\
		src/errors/my_cmd_error.c					\
		src/where/where.c

INCLUDE	=	-I./include

CLIB	=	-L./lib/my -lmy

CFLAGS	=	-W -Wall -Wextra $(INCLUDE) $(CLIB)

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:		$(OBJ)
		make -C ./lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -g

clean:
		make clean -C ./lib/my/
		rm -f $(OBJ) *~

fclean:		clean
		make fclean -C ./lib/my/
		rm -f $(NAME)

re:		fclean all
