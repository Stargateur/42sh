/*
** my_exec.h for my_exec in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:50:34 2014 Antoine Plaskowski
** Last update Sat May 17 03:17:49 2014 Antoine Plaskowski
*/

#ifndef		MY_EXEC_H_
# define	MY_EXEC_H_

# include	"my_btree.h"

typedef	struct	s_fct_e	t_fct_e;

struct          s_fct_e
{
  int		(*fct)(t_btree *btree, char **env);
  t_type	type;
};

int		my_exec(t_btree *, char **);

int		my_exec_pipe(t_btree *btree, char **env);

int		my_exec_comma(t_btree *btree, char **env);

int		my_exec_or(t_btree *btree, char **env);

int		my_exec_and(t_btree *btree, char **env);

int		my_exec_sright(t_btree *, char **);

int		my_exec_dright(t_btree *, char **);

int		my_exec_sleft(t_btree *, char **);

int		my_exec_dleft(t_btree *, char **);

int		my_exec_word(t_btree *btree, char **env);

int		my_cmd(t_btree *, char **);

int		my_execve(t_btree *btree, char **env);

int		my_redirection(char *, int);

#endif		/* !MY_EXEC_H_ */
