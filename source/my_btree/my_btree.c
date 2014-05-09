/*
** my_btree.c for my_btree in /home/plasko_a/rendu/PSU_2013_42sh/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed May  7 20:15:39 2014 Antoine Plaskowski
** Last update Fri May  9 11:31:36 2014 Antoine Plaskowski
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
  if (token == NULL)
    return (NULL);
  my_putstr("priorité la plus haute\n", 1);
  my_aff_token(my_give_high_priority(token), 1);
  return (NULL);
}
