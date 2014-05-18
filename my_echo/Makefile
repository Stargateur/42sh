##
## Makefile for Makefile in /home/marsil_g/Documents/PSU/PSU-MS1/MS
## 
## Made by Gabriele Marsili
## Login   <marsil_g@epitech.net>
## 
## Started on  Thu Dec 19 22:08:53 2013 Gabriele Marsili
## Last update Sun May 18 14:54:34 2014 Gabriele Marsili
##

SRC	=		lib/get_next_line.c 	\
			lib/functions.c 	\
			lib/func2.c 		\
			main.c			\
			echo.c			\
			norm_echo.c		\
			lib/my_fputstr.c	\
			lib/my_fputchar.c	\
			lib/str_to_wordtab.c	\
			check.c			\
			my_free.c		\

CC	=		gcc

CFLAGS	=		-Wall -W -g -Wextra -I .

NAME	=		echo

RM	=		rm -f

OBJ 	=		$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
