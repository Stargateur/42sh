/*
** my_btree_normal.c for my_btree_normal in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_btree
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May 14 07:41:55 2014 Antoine Plaskowski
** Last update Wed May 14 07:46:55 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_typedef.h"

static int	my_btree_normal(t_token *token, t_btree *btree)
{
  if (token == NULL || btree == NULL)
    return (1);
  if (token->prev != NULL)
    {
      token->prev->next = NULL;
      btree->left = my_btree(token->prev);
      token->prev = NULL;
    }
  else
    return (1);
  if (token->next != NULL)
    {
      token->next->prev = NULL;
      btree->right = my_btree(token->next);
      token->next = NULL;
    }
  else
    return (1);
  return (0);
}
