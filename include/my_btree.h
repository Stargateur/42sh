/*
** my_btree.h for my_btree in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 20:11:57 2014 Antoine Plaskowski
** Last update Wed May  7 20:14:43 2014 Antoine Plaskowski
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

#endif		/* !MY_BTREE_H_ */
