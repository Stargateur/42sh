##
## Makefile for my_prompt in /home/makusa_n/depot_git/PSU_2013_42sh/my_prompt
##
## Made by Nayden Makusa
## Login   <makusa_n@epitech.net>
##
## Started on  Fri May 16 12:12:42 CEST 2014 Nayden Makusa
##

CC		=	gcc -g

RM		=	rm -f

NAME		=	my_conf

SRCS		=	my_conf.c \
			get_next_line.c \
			my_str.c \
			my_check_file.c \
			my_msg_check_file.c

OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
