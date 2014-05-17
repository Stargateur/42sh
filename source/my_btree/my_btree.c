/*
** my_btree.c for my_btree in /home/plasko_a/rendu/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 20:15:39 2014 Antoine Plaskowski
** Last update Sat May 17 18:43:57 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_btree.h"
#include	"my_token.h"
#include	"my_str.h"
#include	"my_typedef.h"

static t_fct_b	g_fct_btree[] =
  {
    {&my_btree_normal, O_OR},
    {&my_btree_normal, O_AND},
    {&my_btree_comma, O_COMMA},
    {&my_btree_normal, O_PIPE},
    {NULL, NONE}
  };

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

static t_btree	*my_loop_fct(t_token *token, t_btree *btree)
{
  t_uint	i;

  i = 0;
  while (g_fct_btree[i].fct != NULL)
    {
      if (token->type == g_fct_btree[i].type)
	{
	  if (g_fct_btree[i].fct(token, btree))
	    {
	      my_free_all_btree(btree);
	      return (NULL);
	    }
	  return (btree);
	}
      i++;
    }
  return (my_put_error_null("WTF GIT BLAME NOW\n"));
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
  return (my_loop_fct(tmp, btree));
}
