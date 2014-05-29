##
## SRC.mk for SRC in /home/plasko_a/rendu/PSU_2013_42sh
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue May  6 13:27:09 2014 Antoine Plaskowski
## Last update Thu May 29 15:07:07 2014 Pierrick Gicquelais
##

PATH_SRC	=	source/
PATH_STR	=	$(PATH_SRC)my_str/
PATH_TOKEN	=	$(PATH_SRC)my_token/
PATH_BTREE	=	$(PATH_SRC)my_btree/
PATH_ENV	=	$(PATH_SRC)my_env/
PATH_ECHO	=	$(PATH_SRC)my_echo/
PATH_HISTO	=	$(PATH_SRC)my_history/
PATH_EXEC	=	$(PATH_SRC)my_exec/
PATH_SHELL	=	$(PATH_SRC)my_shell/
PATH_TERM	=	$(PATH_SRC)my_termcaps/
PATH_EDIT	=	$(PATH_SRC)my_edit/

SRC		=	$(PATH_SRC)main.c

SRC		+=	$(PATH_SHELL)my_shell.c
SRC		+=	$(PATH_SHELL)my_exit.c
SRC		+=	$(PATH_SHELL)my_cd.c
SRC		+=	$(PATH_SHELL)my_builtin.c

SRC		+=	$(PATH_EXEC)my_exec.c
SRC		+=	$(PATH_EXEC)my_exec_pipe.c
SRC		+=	$(PATH_EXEC)my_exec_comma.c
SRC		+=	$(PATH_EXEC)my_exec_or.c
SRC		+=	$(PATH_EXEC)my_exec_and.c
SRC		+=	$(PATH_EXEC)my_redir_right.c
SRC		+=	$(PATH_EXEC)my_redir_dright.c
SRC		+=	$(PATH_EXEC)my_redir_left.c
SRC		+=	$(PATH_EXEC)my_redir_dleft.c
SRC		+=	$(PATH_EXEC)my_exec_cmd.c
SRC		+=	$(PATH_EXEC)my_execve.c
SRC		+=	$(PATH_EXEC)my_redirection.c
SRC		+=	$(PATH_EXEC)my_close_fd.c
SRC		+=	$(PATH_EXEC)my_dup_fd.c
SRC		+=	$(PATH_EXEC)my_exec_pipe_first.c
SRC		+=	$(PATH_EXEC)my_exec_pipe_last.c
SRC		+=	$(PATH_EXEC)my_init_fd.c
SRC		+=	$(PATH_EXEC)my_found_exe.c
SRC		+=	$(PATH_EXEC)my_check_exe.c
SRC		+=	$(PATH_EXEC)my_dir.c
SRC		+=	$(PATH_EXEC)my_append_pid.c
SRC		+=	$(PATH_EXEC)my_wait_pid.c
SRC		+=	$(PATH_EXEC)my_aff_signal.c

SRC		+=	$(PATH_HISTO)my_history.c
SRC		+=	$(PATH_HISTO)my_new_history.c
SRC		+=	$(PATH_HISTO)my_node_history.c
SRC		+=	$(PATH_HISTO)my_append_history.c
SRC		+=	$(PATH_HISTO)my_aff_history.c
SRC		+=	$(PATH_HISTO)my_free_history.c
SRC		+=	$(PATH_HISTO)my_check_history.c
SRC		+=	$(PATH_HISTO)my_len_history.c

SRC		+=	$(PATH_ECHO)echo.c
SRC		+=	$(PATH_ECHO)check.c
SRC		+=	$(PATH_ECHO)check_slash.c
SRC		+=	$(PATH_ECHO)norm_echo.c

SRC		+=	$(PATH_ENV)my_env.c
SRC		+=	$(PATH_ENV)my_exec_env.c
SRC		+=	$(PATH_ENV)my_new_env.c
SRC		+=	$(PATH_ENV)my_first_env.c
SRC		+=	$(PATH_ENV)my_last_env.c
SRC		+=	$(PATH_ENV)my_append_env.c
SRC		+=	$(PATH_ENV)my_put_env.c
SRC		+=	$(PATH_ENV)my_aff_env.c
SRC		+=	$(PATH_ENV)my_free_env.c
SRC		+=	$(PATH_ENV)my_copy_env.c
SRC		+=	$(PATH_ENV)my_cpy_env.c
SRC		+=	$(PATH_ENV)my_len_env.c
SRC		+=	$(PATH_ENV)my_env_to_tab.c
SRC		+=	$(PATH_ENV)my_add_env.c
SRC		+=	$(PATH_ENV)my_found_env.c
SRC		+=	$(PATH_ENV)my_sup_env.c
SRC		+=	$(PATH_ENV)my_setenv.c
SRC		+=	$(PATH_ENV)my_unsetenv.c

SRC		+=	$(PATH_BTREE)my_btree.c
SRC		+=	$(PATH_BTREE)my_new_btree.c
SRC		+=	$(PATH_BTREE)my_new_btree_token.c
SRC		+=	$(PATH_BTREE)my_aff_btree.c
SRC		+=	$(PATH_BTREE)my_free_btree.c
SRC		+=	$(PATH_BTREE)my_btree_comma.c
SRC		+=	$(PATH_BTREE)my_btree_normal.c
SRC		+=	$(PATH_BTREE)my_check_btree.c
SRC		+=	$(PATH_BTREE)my_check_pipe_btree.c
SRC		+=	$(PATH_BTREE)my_check_cmd_btree.c

SRC		+=	$(PATH_TOKEN)my_token.c
SRC		+=	$(PATH_TOKEN)my_found_token.c
SRC		+=	$(PATH_TOKEN)my_aff_token.c
SRC		+=	$(PATH_TOKEN)my_append_token.c
SRC		+=	$(PATH_TOKEN)my_token_word_to_tab.c
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
SRC		+=	$(PATH_TOKEN)my_nbr_token_o_rleft.c
SRC		+=	$(PATH_TOKEN)my_nbr_token_o_rdleft.c
SRC		+=	$(PATH_TOKEN)my_nbr_token_o_rright.c
SRC		+=	$(PATH_TOKEN)my_nbr_token_o_rdright.c

SRC		+=	$(PATH_STR)my_putchar.c
SRC		+=	$(PATH_STR)my_putstr.c
SRC		+=	$(PATH_STR)my_putnbr.c
SRC		+=	$(PATH_STR)my_putnbr_base.c
SRC		+=	$(PATH_STR)my_strlen.c
SRC		+=	$(PATH_STR)my_strcat.c
SRC		+=	$(PATH_STR)my_strcmp.c
SRC		+=	$(PATH_STR)my_strncmp.c
SRC		+=	$(PATH_STR)my_strcpy.c
SRC		+=	$(PATH_STR)my_strncpy.c
SRC		+=	$(PATH_STR)my_strlcpy.c
SRC		+=	$(PATH_STR)my_strdup.c
SRC		+=	$(PATH_STR)my_strndup.c
SRC		+=	$(PATH_STR)my_strldup.c
SRC		+=	$(PATH_STR)my_getnbr.c
SRC		+=	$(PATH_STR)my_getnbr_base.c
SRC		+=	$(PATH_STR)my_malloc.c
SRC		+=	$(PATH_STR)my_char_in_str.c
SRC		+=	$(PATH_STR)my_epur_str.c
SRC		+=	$(PATH_STR)my_put_str.c
SRC		+=	$(PATH_STR)my_new_str.c
SRC		+=	$(PATH_STR)my_append_str.c
SRC		+=	$(PATH_STR)my_free_str.c
SRC		+=	$(PATH_STR)my_aff_str.c
SRC		+=	$(PATH_STR)my_first_str.c
SRC		+=	$(PATH_STR)my_last_str.c
SRC		+=	$(PATH_STR)my_open.c
SRC		+=	$(PATH_STR)my_get_next_line.c
SRC		+=	$(PATH_STR)my_tab.c
SRC		+=	$(PATH_STR)my_str_to_tab.c
SRC		+=	$(PATH_STR)my_put_error.c
SRC		+=	$(PATH_STR)my_sign_nbr.c
SRC		+=	$(PATH_STR)my_is_num.c
SRC		+=	$(PATH_STR)my_check_overflow_int.c
SRC		+=	$(PATH_STR)my_nbr_to_str.c
SRC		+=	$(PATH_STR)my_str_in_tab.c
SRC		+=	$(PATH_STR)my_strcmp_icase.c
SRC		+=	$(PATH_STR)my_pipe.c
SRC		+=	$(PATH_STR)my_dup2.c
SRC		+=	$(PATH_STR)is_positive.c
SRC		+=	$(PATH_STR)is_alpha.c
SRC		+=	$(PATH_STR)is_dir.c

SRC		+=	$(PATH_TERM)my_echo_off.c
SRC		+=	$(PATH_TERM)my_putint.c
SRC		+=	$(PATH_TERM)my_raw_mode.c
SRC		+=	$(PATH_TERM)my_reset.c
SRC		+=	$(PATH_TERM)my_tcgetattr.c
SRC		+=	$(PATH_TERM)my_tgetent.c
SRC		+=	$(PATH_TERM)my_tgetstr.c

SRC		+=	$(PATH_EDIT)term_init.c
