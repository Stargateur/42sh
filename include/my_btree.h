/*
** my_btree.h for my_btree in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 20:11:57 2014 Antoine Plaskowski
** Last update Fri May  9 14:18:34 2014 Pierrick Gicquelais
*/

#ifndef		MY_BTREE_H_
# define	MY_BTREE_H_

# include	"my_token.h"

typedef	struct	s_btree	t_btree;

struct		s_btree
{
  t_btree	*left;
  t_btree	*right;
  t_token	*token;
};

t_btree		*my_new_btree(void);

t_btree		*my_new_btree_token(t_token *token);

t_btree		*my_btree(t_token *token);

int		my_aff_btree(t_btree *, const int);

int		my_aff_all_btree(t_btree *, const int);

#endif		/* !MY_BTREE_H_ */
