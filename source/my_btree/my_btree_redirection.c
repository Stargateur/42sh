/*
** my_btree_redirection.c for my_btree_redirection in /home/plasko_a/programation/epitech/PSU_2013_42sh/source/my_btree
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May 14 07:41:55 2014 Antoine Plaskowski
** Last update Thu May 15 19:59:45 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_typedef.h"

static t_token	*my_sup_token_redic(t_token *token)
{
  t_token	*word;

  word = NULL;
  if (token->next->next != NULL)
    {
      word = token->next->next;
      token->next->next->prev = token->prev;
    }
  if (token->prev != NULL)
    {
      word = token->prev;
      token->prev->next = token->next->next;
    }
  return (word);
}

int		my_btree_redirection(t_token *token, t_btree *btree)
{
  t_token	*word;

  if (token == NULL || token->next == NULL || btree == NULL)
    return (1);
  if ((word = my_sup_token_redic(token)) == NULL)
    return (1);
  btree->left = my_btree(word);
  token->prev = NULL;
  token->next->prev = NULL;
  token->next->next = NULL;
  btree->right = my_btree(token->next);
  token->next = NULL;
  return (0);
}
