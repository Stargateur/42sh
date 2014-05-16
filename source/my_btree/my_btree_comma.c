/*
** my_btree_comma.c for my_btree_comma in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_btree
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May 14 07:41:55 2014 Antoine Plaskowski
** Last update Fri May 16 02:37:57 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_typedef.h"

int		my_btree_comma(t_token *token, t_btree *btree)
{
  int		ret;

  if (token == NULL || btree == NULL)
    return (1);
  ret = 0;
  if (token->prev != NULL)
    {
      token->prev->next = NULL;
      if ((btree->left = my_btree(token->prev)) == NULL)
	ret = 1;
      token->prev = NULL;
    }
  if (token->next != NULL)
    {
      token->next->prev = NULL;
      if ((btree->right = my_btree(token->next)) == NULL)
	ret = 1;
      token->next = NULL;
    }
  return (ret);
}
