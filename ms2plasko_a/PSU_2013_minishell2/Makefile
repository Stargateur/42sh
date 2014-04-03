##
## Makefile for fdf in /home/plasko_a/rendu/MUL_2013_fdf
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Thu Nov 21 08:52:14 2013 Antoine Plaskowski
## Last update Mon Mar 31 14:37:16 2014 Gabriele Marsili
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -O3
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I include/

LDFLAGS	+=

NAME	=	mysh

SRC	+=	src/main.c

SRC	+=	src/my_check_input.c
SRC	+=	src/my_check_error.c
SRC	+=	src/my_check_builtins.c
SRC	+=	src/my_create_argv.c
SRC	+=	src/my_search_redir.c
SRC	+=	src/my_struct_cmd.c
SRC	+=	src/my_management.c
SRC	+=	src/my_redirection.c

SRC	+=	src/my_pwd.c
SRC	+=	src/my_cd.c
SRC	+=	src/my_env.c

SRC	+=	src/my_tool_env.c
SRC	+=	src/my_tool_tab.c
SRC	+=	src/my_tool_redir.c

SRC	+=	src/my_putchar.c
SRC	+=	src/my_putstr.c
SRC	+=	src/my_getnbr.c
SRC	+=	src/my_strlen.c
SRC	+=	src/my_strcpy.c
SRC	+=	src/my_strdup.c
SRC	+=	src/my_strcat.c
SRC	+=	src/my_strcmp.c
SRC	+=	src/my_strncmp.c
SRC	+=	src/my_malloc.c
SRC	+=	src/my_get_next_line.c

SRC	+=	src/my_dir.c
SRC	+=	src/my_open.c
SRC	+=	src/my_fork.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
