##
## Makefile for Makefile in /home/marsil_g/Documents/PSU/PSU-MS2/MS
## 
## Made by Gabriele Marsili
## Login   <marsil_g@epitech.net>
## 
## Started on  Thu Dec 19 22:08:53 2013 Gabriele Marsili
## Last update Wed Mar  5 15:55:28 2014 marsil_g
##

SRC	=		ms2.c 			\
			get_next_line.c 	\
			functions.c 		\
			str_to_wordtab.c 	\
			path_tab.c		\
			main.c			\
			built_in.c		\
			msbis.c			\
			pth.c			\
			func2.c			\
			free.c			\

CC	=		gcc

CFLAGS	=		-Wall -W -g -Wextra

NAME	=		mysh

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
