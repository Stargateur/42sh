/*
** my_exec.h for my_exec in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:50:34 2014 Antoine Plaskowski
** Last update Sat May 17 20:04:09 2014 Antoine Plaskowski
*/

#ifndef		MY_EXEC_H_
# define	MY_EXEC_H_

# include	"my_btree.h"

typedef	struct	s_fct_e	t_fct_e;
typedef	struct	s_fct_r	t_fct_r;
typedef	struct	s_fd	t_fd;

struct		s_fct_e
{
  int		(*fct)(t_btree *btree, char **env);
  t_type	type;
};

struct		s_fct_r
{
  int		(*fct)(t_token *token, t_fd *fd);
  t_type	type;
};

struct		s_fd
{
  int		fd_0;
  int		fd_1;
  int		fd_pipe[2];
};

int		my_exec(t_btree *, char **);

int		my_exec_pipe(t_btree *btree, char **env);

int		my_exec_comma(t_btree *btree, char **env);

int		my_exec_or(t_btree *btree, char **env);

int		my_exec_and(t_btree *btree, char **env);

int		my_redir_right(t_token *token, t_fd *fd);

int		my_redir_dright(t_token *token, t_fd *fd);

int		my_redir_left(t_token *token, t_fd *fd);

int		my_redir_dleft(t_token *token, t_fd *fd);

int		my_exec_cmd(t_btree *btree, char **env);

int		my_execve(t_btree *btree, t_fd *fd, char **env);

int		my_redirection(t_token *token, t_fd *fd);

int		my_redir_dleft_in_father(t_token *token, t_fd *fd);

#endif		/* !MY_EXEC_H_ */
