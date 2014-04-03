##
## Makefile for Makefile in /home/plasko_a/rendu/CPE_2014_corewar
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Tue Mar 25 13:37:17 2014 Antoine Plaskowski
## Last update Thu Apr  3 23:02:39 2014 Antoine Plaskowski
##

CC			?=	gcc

DEBUG			?=	0

ifeq ($(DEBUG), 1)
CFLAGS			+=	-g
endif

RM			=	rm -f

MKDIR			=	mkdir -p

CFLAGS			+=	-Wall -Wextra -O3
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-I include/

LDFLAGS			+=

NAME			=	42sh

SRC			+=	src/main.c

SRC			+=	src/standard/my_putchar.c
SRC			+=	src/standard/my_strlen.c
SRC			+=	src/standard/my_strcmp.c
SRC			+=	src/standard/my_strncmp.c
SRC			+=	src/standard/my_strcpy.c
SRC			+=	src/standard/my_strncpy.c
SRC			+=	src/standard/my_strdup.c
SRC			+=	src/standard/my_strndup.c
SRC			+=	src/standard/my_putstr.c
SRC			+=	src/standard/my_putnbr.c
SRC			+=	src/standard/my_putnbr_base.c
SRC			+=	src/standard/my_getnbr.c
SRC			+=	src/standard/my_malloc.c
SRC			+=	src/standard/my_char_in_str.c
SRC			+=	src/standard/my_epur_str.c
SRC			+=	src/standard/my_put_error.c
SRC			+=	src/standard/my_get_next_line.c

OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean			:
				$(RM) $(OBJ)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY			:	all clean fclean re
