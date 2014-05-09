/*
** my_btree.c for my_btree in /home/plasko_a/rendu/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 20:15:39 2014 Antoine Plaskowski
** Last update Fri May  9 14:22:32 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_token.h"
#include	"my_typedef.h"

static t_token	*my_give_high_priority(t_token *token)
{
  t_token	*tmp;
  t_uint	pri_tmp;

  tmp = NULL;
  pri_tmp = 0;
  while (token != NULL)
    {
      if (token->priority && (pri_tmp > token->priority || pri_tmp == 0))
	{
	  pri_tmp = token->priority;
	  tmp = token;
	}
      token = token->next;
    }
  return (tmp);
}

t_btree		*my_btree(t_token *token)
{
  t_btree	*btree;
  t_token	*tmp;

  if ((token = my_first_token(token)) == NULL)
    return (NULL);
  if ((tmp = my_give_high_priority(token)) == NULL)
    return (my_new_btree_token(token));
  if ((btree = my_new_btree()) == NULL)
    return (NULL);
  btree->token = tmp;
  if (tmp->prev != NULL)
    {
      tmp->prev->next = NULL;
      btree->left = my_btree(tmp->prev);
    }
  else
    return (NULL);
  if (tmp->next != NULL)
    {
      tmp->next->prev = NULL;
      btree->right = my_btree(tmp->next);
    }
  else
    return (NULL);
  return (btree);
}
