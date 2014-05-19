/*
** my_btree.h for my_btree in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 20:11:57 2014 Antoine Plaskowski
** Last update Mon May 19 02:25:34 2014 Antoine Plaskowski
*/

#ifndef		MY_BTREE_H_
# define	MY_BTREE_H_

# include	"my_token.h"

typedef	struct	s_btree	t_btree;
typedef	struct	s_fct_b	t_fct_b;

struct		s_btree
{
  t_btree	*left;
  t_btree	*right;
  t_token	*token;
};

struct		s_fct_b
{
  int		(*fct)(t_token *token, t_btree *btree);
  t_type	type;
};

t_btree		*my_new_btree(void);

t_btree		*my_new_btree_token(t_token *token);

t_btree		*my_btree(t_token *token);

int		my_aff_btree(t_btree *, const int);

int		my_aff_all_btree(t_btree *, const int);

void		my_free_btree(t_btree *btree);

void		my_free_all_btree(t_btree *btree);

int		my_btree_normal(t_token *token, t_btree *btree);

int		my_btree_comma(t_token *token, t_btree *btree);

int		my_check_btree(t_btree *btree);

int		my_check_cmd_btree(t_token *token);

int		my_check_pipe_btree(t_btree *btree);

#endif		/* !MY_BTREE_H_ */
