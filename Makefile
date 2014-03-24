##
## Makefile for 42sh in /home/gicque_p/rendu/PSU_2013_42sh
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Mar 24 14:32:36 2014 Pierrick Gicquelais
## Last update Mon Mar 24 14:34:21 2014 Pierrick Gicquelais
##

CC	=	gcc

RM	=	rm -f

NAME	=	42sh

CFLAGS	+=	-I./ -W -Wall -Wextra

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
