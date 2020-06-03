##
## EPITECH PROJECT, 2018
## Huré Yaowanart
## File description:
## Makefile
##

SRC	=	my_strlen.c 			\
		my_putstr.c 			\
		my_putchar.c			\
		my_strcmp.c				\
		my_strcpy.c				\
		my_swap.c				\
		my_put_nbr.c			\
		my_getnbr.c				\
		my_strcat.c				\
		my_str_to_word_tab.c	\
		my_strncmp.c			\
		my_strdup.c				\
		my_strndup.c			\
		my_strcat_mini.c		\
		my_clean_str.c			\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		my_free_array.c			\
		my_scane_str.c			\
		my_dup_one_more.c		\
		my_str_malloc.c			\
		my_strtwa.c				\
		my_len_array.c			\
		my_str_to_tab.c			\
		my_find_char.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
