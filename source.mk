##
## SRC.mk for SRC in /home/plasko_a/rendu/PSU_2013_42sh
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue May  6 13:27:09 2014 Antoine Plaskowski
## Last update Wed May  7 17:30:44 2014 Antoine Plaskowski
##

PATH_SRC	=	source/

PATH_STR	=	$(PATH_SRC)my_str/
PATH_TOK	=	$(PATH_SRC)my_token/

SRC		=	$(PATH_SRC)main.c

SRC		+=	$(PATH_TOK)my_token.c
SRC		+=	$(PATH_TOK)my_aff_token.c
SRC		+=	$(PATH_TOK)my_append_token.c
SRC		+=	$(PATH_TOK)my_free_token.c
SRC		+=	$(PATH_TOK)my_first_token.c
SRC		+=	$(PATH_TOK)my_last_token.c

SRC		+=	$(PATH_STR)my_putchar.c
SRC		+=	$(PATH_STR)my_putstr.c
SRC		+=	$(PATH_STR)my_putnbr.c
SRC		+=	$(PATH_STR)my_putnbr_base.c
SRC		+=	$(PATH_STR)my_strlen.c
SRC		+=	$(PATH_STR)my_strcmp.c
SRC		+=	$(PATH_STR)my_strncmp.c
SRC		+=	$(PATH_STR)my_strcpy.c
SRC		+=	$(PATH_STR)my_strncpy.c
SRC		+=	$(PATH_STR)my_strdup.c
SRC		+=	$(PATH_STR)my_strndup.c
SRC		+=	$(PATH_STR)my_getnbr.c
SRC		+=	$(PATH_STR)my_getnbr_base.c
SRC		+=	$(PATH_STR)my_malloc.c
SRC		+=	$(PATH_STR)my_char_in_str.c
SRC		+=	$(PATH_STR)my_epur_str.c
SRC		+=	$(PATH_STR)my_str.c
SRC		+=	$(PATH_STR)my_open.c
SRC		+=	$(PATH_STR)my_fork.c
SRC		+=	$(PATH_STR)my_get_next_line.c
SRC		+=	$(PATH_STR)my_tab.c
SRC		+=	$(PATH_STR)my_str_to_tab.c
SRC		+=	$(PATH_STR)my_put_error.c
SRC		+=	$(PATH_STR)my_sign_nbr.c
SRC		+=	$(PATH_STR)my_is_num.c
