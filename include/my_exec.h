/*
** my_exec.h for my_exec in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:50:34 2014 Antoine Plaskowski
** Last update Thu May 29 16:24:11 2014 Antoine Plaskowski
*/

#ifndef		MY_EXEC_H_
# define	MY_EXEC_H_

# include	<dirent.h>
# include	"my_shell.h"
# include	"my_btree.h"

typedef	struct	s_fct_e	t_fct_e;
typedef	struct	s_fct_r	t_fct_r;

struct		s_fct_e
{
  int		(*fct)(t_btree *btree, t_shell *shell);
  t_type	type;
};

struct		s_fct_r
{
  int		(*fct)(t_token *token, t_fd *fd);
  t_type	type;
};

int		my_exec(t_btree *btree, t_shell *shell);

int		my_exec_pipe(t_btree *btree, t_shell *shell);

int		my_exec_pipe_first(t_btree *btree, t_fd *fd, t_shell *shell);

int		my_exec_pipe_last(t_btree *btree, t_fd *fd, t_shell *shell);

int		my_exec_comma(t_btree *btree, t_shell *shell);

int		my_exec_or(t_btree *btree, t_shell *shell);

int		my_exec_and(t_btree *btree, t_shell *shell);

int		my_redir_right(t_token *token, t_fd *fd);

int		my_redir_dright(t_token *token, t_fd *fd);

int		my_redir_left(t_token *token, t_fd *fd);

int		my_redir_dleft(t_token *token, t_fd *fd);

int		my_exec_cmd(t_btree *btree, t_shell *shell);

void		my_execve(t_btree *btree, t_fd *fd, t_shell *shell);

int		my_redirection(t_token *token, t_fd *fd);

int		my_redir_dleft_in_father(t_token *token, t_fd *fd);

int		my_aff_redir_dleft(t_fd *fd);

int		my_close_fd(t_fd *fd);

int		my_init_fd(t_fd *fd);

int		my_dup_fd(t_fd *fd);

int		my_chdir(const char*path);

DIR		*my_open_dir(const char*path);

int		my_close_dir(DIR* dir);

char		*my_cat_dir(const char*dir, const char*name);

int		my_check_exe(char *exe);

char		*my_found_exe(t_env *env, char *str);

int		my_wait_pid(t_pid *pid);

int		my_aff_signal(int signal);

int		my_env_exec(t_env *env, char **argv, t_fd *fd, t_shell *shell);

#endif		/*!MY_EXEC_H_*/
