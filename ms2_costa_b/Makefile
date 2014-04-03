##
## Makefile for Makefile in /home/costa_b/rendu/CPE_2013_BSQ
## 
## Made by Kevin Costa
## Login   <costa_b@epitech.net>
## 
## Started on  Fri Dec  6 18:44:40 2013 Kevin Costa
## Last update Fri Mar  7 18:21:13 2014 Kevin Costa
##

CC	=		gcc

NAME	=		mysh

CFLAGS	+=		-Wall -Wextra
CFLAGS	+=		-pedantic -ansi

LDFLAGS =               -lmlx -lXext -lX11

SRC	=		my_lib.c		\
			my_lib2.c		\
			get_next_line.c		\
			minishell2.c		\
			my_cpy_env.c		\
			my_str_to_word_tab.c	\
			my_path_to_word_tab.c	\
			check_buffer.c		\
			my_exec.c

OBJ	=		$(SRC:.c=.o)

all :			$(NAME)

$(NAME) :		$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean : 
			rm -rf $(OBJ)

fclean : 		clean
			rm -rf $(NAME)

re : 			fclean all
