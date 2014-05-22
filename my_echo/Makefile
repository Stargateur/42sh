##
## Makefile for Makefile in /home/marsil_g/Documents/PSU/PSU-MS1/MS
## 
## Made by Gabriele Marsili
## Login   <marsil_g@epitech.net>
## 
## Started on  Thu Dec 19 22:08:53 2013 Gabriele Marsili
## Last update Thu May 22 16:12:59 2014 Gabriele Marsili
##

SRC	=		lib/get_next_line.c 	\
			../source/my_str/my_putchar.c\
			../source/my_str/my_putstr.c\
			../source/my_str/my_strcmp.c\
			../source/my_str/my_epur_str.c\
			../source/my_str/my_str_to_tab.c\
			../source/my_str/my_char_in_str.c\
			../source/my_str/my_malloc.c\
			../source/my_str/my_strlen.c\
			main.c			\
			echo.c			\
			norm_echo.c		\
			check.c			\
			check_slash.c		\

CC	=		gcc

CFLAGS	=		-Wall -W -g -Wextra -I . -I ../include/

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
