##
## Makefile for Makefile in /home/plasko_a/rendu/CPE_2014_corewar
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Tue Mar 25 13:37:17 2014 Antoine Plaskowski
## Last update Wed May  7 16:34:43 2014 Antoine Plaskowski
##

CC			=	gcc

DEBUG			=	no

LEVEL			=	3

RM			=	rm -f

ECHO			=	/bin/echo -e

MKDIR			=	mkdir -p

RMDIR			=	rmdir

GREEN			=	\e[32m
YELLOW			=	\e[33m
RED			=	\e[31m
WHITE			=	\e[m

CFLAGS			=	-Wall -Wextra -O$(LEVEL)
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-I include/

ifeq ($(DEBUG), yes)
CFLAGS			+=	-g
endif

LDFLAGS			=

DFLAGS			=	-Yinclude/ -w80

NAME			=	42sh

include				source.mk

OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				@$(ECHO) "$(GREEN)\n\t>> COMPILATION SUCCESSFUL\n$(WHITE)"
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
				@$(ECHO) "$(YELLOW)\n\t>> LINKING SUCCESSFUL\n$(WHITE)"

clean			:
				$(RM) $(OBJ)
				@$(ECHO) "$(RED)\n\t>> CLEANING BINAIRIES SUCCESSFUL\n$(WHITE)"

fclean			:	clean
				$(RM) $(NAME)
				@$(ECHO) "$(RED)\n\t>> CLEANING EXECUTABLE SUCCESSFUL\n$(WHITE)"

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

source/main.o: include/my_token.h include/my_typedef.h include/my_btree.h
source/main.o: include/my_str.h include/my_exec.h include/my_env.h
source/my_exec/my_exec.o: include/my_exec.h include/my_btree.h
source/my_exec/my_exec.o: include/my_token.h include/my_typedef.h
source/my_exec/my_exec.o: include/my_str.h
source/my_exec/my_exec_pipe.o: include/my_exec.h include/my_btree.h
source/my_exec/my_exec_pipe.o: include/my_token.h include/my_typedef.h
source/my_exec/my_exec_pipe.o: include/my_str.h
source/my_exec/my_exec_comma.o: include/my_exec.h include/my_btree.h
source/my_exec/my_exec_comma.o: include/my_token.h include/my_typedef.h
source/my_exec/my_exec_or.o: include/my_exec.h include/my_btree.h
source/my_exec/my_exec_or.o: include/my_token.h include/my_typedef.h
source/my_exec/my_exec_and.o: include/my_exec.h include/my_btree.h
source/my_exec/my_exec_and.o: include/my_token.h include/my_typedef.h
source/my_exec/my_exec_word.o: include/my_exec.h include/my_btree.h
source/my_exec/my_exec_word.o: include/my_token.h include/my_typedef.h
source/my_exec/my_cmd.o: include/my_exec.h include/my_btree.h
source/my_exec/my_cmd.o: include/my_token.h include/my_typedef.h
source/my_exec/my_cmd.o: include/my_str.h
source/my_exec/my_execve.o: include/my_exec.h include/my_btree.h
source/my_exec/my_execve.o: include/my_token.h include/my_typedef.h
source/my_exec/my_execve.o: include/my_str.h
source/my_exec/my_redirection.o: include/my_exec.h include/my_btree.h
source/my_exec/my_redirection.o: include/my_token.h include/my_typedef.h
source/my_exec/my_redirection.o: include/my_str.h
source/my_exec/my_sright_redirection.o: include/my_btree.h include/my_token.h
source/my_exec/my_sright_redirection.o: include/my_typedef.h include/my_str.h
source/my_exec/my_dright_redirection.o: include/my_str.h include/my_typedef.h
source/my_exec/my_sleft_redirection.o: include/my_str.h include/my_typedef.h
source/my_exec/my_dleft_redirection.o: include/my_str.h include/my_typedef.h
source/my_env/my_env.o: include/my_env.h include/my_str.h include/my_typedef.h
source/my_env/my_new_env.o: include/my_env.h include/my_str.h
source/my_env/my_new_env.o: include/my_typedef.h
source/my_env/my_first_env.o: include/my_env.h
source/my_env/my_last_env.o: include/my_env.h
source/my_env/my_append_env.o: include/my_env.h
source/my_env/my_aff_env.o: include/my_env.h include/my_str.h
source/my_env/my_aff_env.o: include/my_typedef.h
source/my_env/my_free_env.o: include/my_env.h
source/my_btree/my_btree.o: include/my_btree.h include/my_token.h
source/my_btree/my_btree.o: include/my_typedef.h
source/my_btree/my_new_btree.o: include/my_btree.h include/my_token.h
source/my_btree/my_new_btree.o: include/my_typedef.h include/my_str.h
source/my_btree/my_new_btree_token.o: include/my_btree.h include/my_token.h
source/my_btree/my_new_btree_token.o: include/my_typedef.h
source/my_btree/my_aff_btree.o: include/my_btree.h include/my_token.h
source/my_btree/my_aff_btree.o: include/my_typedef.h include/my_str.h
source/my_btree/my_free_btree.o: include/my_btree.h include/my_token.h
source/my_btree/my_free_btree.o: include/my_typedef.h
source/my_token/my_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_token.o: include/my_str.h
source/my_token/my_aff_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_aff_token.o: include/my_str.h
source/my_token/my_append_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_append_token.o: include/my_str.h
source/my_token/my_token_word_to_tab.o: include/my_token.h include/my_typedef.h
source/my_token/my_token_word_to_tab.o: include/my_str.h
source/my_token/my_put_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_put_token.o: include/my_str.h
source/my_token/my_len_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_free_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_free_token.o: include/my_str.h
source/my_token/my_first_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_last_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_new_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_new_token.o: include/my_str.h
source/my_token/my_or_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_and_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_comma_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_pipe_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_word_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_word_token.o: include/my_str.h
source/my_token/my_esperluette_token.o: include/my_token.h include/my_typedef.h
source/my_token/my_redirection_left_token.o: include/my_token.h
source/my_token/my_redirection_left_token.o: include/my_typedef.h
source/my_token/my_redirection_right_token.o: include/my_token.h
source/my_token/my_redirection_right_token.o: include/my_typedef.h
source/my_token/my_redirection_double_left_token.o: include/my_token.h
source/my_token/my_redirection_double_left_token.o: include/my_typedef.h
source/my_token/my_redirection_double_right_token.o: include/my_token.h
source/my_token/my_redirection_double_right_token.o: include/my_typedef.h
source/my_str/my_putchar.o: include/my_str.h include/my_typedef.h
source/my_str/my_putstr.o: include/my_str.h include/my_typedef.h
source/my_str/my_putnbr.o: include/my_str.h include/my_typedef.h
source/my_str/my_putnbr_base.o: include/my_str.h include/my_typedef.h
source/my_str/my_strlen.o: include/my_typedef.h
source/my_str/my_strcat.o: include/my_str.h include/my_typedef.h
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
source/my_str/my_fork.o: include/my_str.h include/my_typedef.h
source/my_str/my_get_next_line.o: include/my_str.h include/my_typedef.h
source/my_str/my_tab.o: include/my_str.h include/my_typedef.h
source/my_str/my_str_to_tab.o: include/my_str.h include/my_typedef.h
source/my_str/my_put_error.o: include/my_str.h include/my_typedef.h
source/my_str/my_check_overflow_int.o: include/my_str.h include/my_typedef.h
source/my_str/my_nbr_to_str.o: include/my_typedef.h
source/my_str/my_str_in_tab.o: include/my_str.h include/my_typedef.h
source/my_str/my_pipe.o: include/my_str.h include/my_typedef.h
source/my_str/my_dup2.o: include/my_str.h include/my_typedef.h
