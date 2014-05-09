/*
** my_btree.h for my_btree in /home/plasko_a/rendu/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 20:11:57 2014 Antoine Plaskowski
** Last update Fri May  9 10:49:32 2014 Antoine Plaskowski
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

enum
  {
    P_WORD = 0,
    P_O_OR = 2,
    P_O_AND = 2,
    P_O_COMA = 1,
    P_O_PIPE = 3,
    P_O_RLEFT = 0,
    P_O_RDLEFT = 0,
    P_O_RRIGHT = 0,
    P_O_RDRIGHT = 0,
    P_NONE = 0
  };

#endif		/* !MY_BTREE_H_ */
