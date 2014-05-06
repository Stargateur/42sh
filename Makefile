##
## Makefile for Makefile in /home/plasko_a/rendu/CPE_2014_corewar
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Tue Mar 25 13:37:17 2014 Antoine Plaskowski
## Last update Mon May  5 14:54:47 2014 Pierrick Gicquelais
##

CC			=	gcc

DEBUG			=	no

LEVEL			=	3

RM			=	rm -f

MKDIR			=	mkdir -p

RMDIR			=	rmdir

CFLAGS			=	-Wall -Wextra -O$(LEVEL)
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-I include/

ifeq ($(DEBUG), yes)
CFLAGS			+=	-g
endif

LDFLAGS			=

DFLAGS			=	-Yinclude/ -w80

NAME			=	42sh

include				SRC.mk

OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean			:
				$(RM) $(OBJ)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

depend			:
				makedepend $(SRC) $(DFLAGS)

%.o			:	%.c
				$(CC) -c $< -o $@ $(CFLAGS)

%.s			:	%.c
				$(CC) -S $< -o $@ $(CFLAGS)

.PHONY			:	all clean fclean re %.o %.s

.SUFFIXES		:	.o.c .s.c

# DO NOT DELETE

source/main.o: include/my_token.h include/my_str.h include/my_typedef.h
source/my_token/my_token.o: include/my_token.h
source/my_str/my_putchar.o: include/my_str.h include/my_typedef.h
source/my_str/my_putstr.o: include/my_str.h include/my_typedef.h
source/my_str/my_putnbr.o: include/my_str.h include/my_typedef.h
source/my_str/my_putnbr_base.o: include/my_str.h include/my_typedef.h
source/my_str/my_strlen.o: include/my_typedef.h
source/my_str/my_strcmp.o: include/my_typedef.h
source/my_str/my_strcpy.o: include/my_typedef.h
source/my_str/my_strncpy.o: include/my_typedef.h
source/my_str/my_strdup.o: include/my_str.h include/my_typedef.h
source/my_str/my_strndup.o: include/my_str.h include/my_typedef.h
source/my_str/my_getnbr.o: include/my_str.h include/my_typedef.h
source/my_str/my_getnbr_base.o: include/my_str.h include/my_typedef.h
source/my_str/my_malloc.o: include/my_typedef.h include/my_str.h
source/my_str/my_epur_str.o: include/my_str.h include/my_typedef.h
source/my_str/my_str.o: include/my_str.h include/my_typedef.h
source/my_str/my_open.o: include/my_str.h include/my_typedef.h
source/my_str/my_get_next_line.o: include/my_str.h include/my_typedef.h
source/my_str/my_tab.o: include/my_str.h include/my_typedef.h
source/my_str/my_str_to_tab.o: include/my_str.h include/my_typedef.h
source/my_str/my_put_error.o: include/my_str.h include/my_typedef.h
