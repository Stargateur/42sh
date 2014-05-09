##
## SRC.mk for SRC in /home/plasko_a/rendu/PSU_2013_42sh
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue May  6 13:27:09 2014 Antoine Plaskowski
## Last update Fri May  9 14:06:02 2014 Pierrick Gicquelais
##

PATH_SRC	=	source/
PATH_STR	=	$(PATH_SRC)my_str/
PATH_TOKEN	=	$(PATH_SRC)my_token/
PATH_BTREE	=	$(PATH_SRC)my_btree/

SRC		=	$(PATH_SRC)main.c

SRC		+=	$(PATH_BTREE)my_btree.c
SRC		+=	$(PATH_BTREE)my_new_btree.c
SRC		+=	$(PATH_BTREE)my_free_btree.c

SRC		+=	$(PATH_TOKEN)my_token.c
SRC		+=	$(PATH_TOKEN)my_aff_token.c
SRC		+=	$(PATH_TOKEN)my_append_token.c
SRC		+=	$(PATH_TOKEN)my_put_token.c
SRC		+=	$(PATH_TOKEN)my_len_token.c
SRC		+=	$(PATH_TOKEN)my_free_token.c
SRC		+=	$(PATH_TOKEN)my_first_token.c
SRC		+=	$(PATH_TOKEN)my_last_token.c
SRC		+=	$(PATH_TOKEN)my_new_token.c
SRC		+=	$(PATH_TOKEN)my_or_token.c
SRC		+=	$(PATH_TOKEN)my_and_token.c
SRC		+=	$(PATH_TOKEN)my_comma_token.c
SRC		+=	$(PATH_TOKEN)my_pipe_token.c
SRC		+=	$(PATH_TOKEN)my_word_token.c
SRC		+=	$(PATH_TOKEN)my_esperluette_token.c
SRC		+=	$(PATH_TOKEN)my_redirection_left_token.c
SRC		+=	$(PATH_TOKEN)my_redirection_right_token.c
SRC		+=	$(PATH_TOKEN)my_redirection_double_left_token.c
SRC		+=	$(PATH_TOKEN)my_redirection_double_right_token.c

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
