/*
** my_exec.h for my_exec in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri May  9 14:50:34 2014 Antoine Plaskowski
** Last update Fri May 16 14:28:33 2014 Pierrick Gicquelais
*/

#ifndef		MY_EXEC_H_
# define	MY_EXEC_H_

# include	"my_btree.h"

typedef	struct	s_list	t_list;

struct		s_list
{
  t_list	*prev;
  t_list	*next;
  char		*att;
};

t_list		*my_new_list();

t_list		*my_first_elem(t_list *);

t_list		*my_last_elem(t_list *);

t_list		*my_append_list(t_list *, char *);

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

void		my_aff_all_list(t_list *);

void		my_free_all_list(t_list *);

#endif		/* !MY_EXEC_H_ */
