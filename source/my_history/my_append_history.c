/*
** my_append_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Wed May 28 18:37:03 2014 Pierrick Gicquelais
** Last update Thu May 29 15:39:53 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_history.h"
#include	"my_str.h"

t_histo		*my_append_history(t_histo *old, char *att)
{
  t_histo	*new;
  static int	id = 1;

  if ((new = my_new_history()) == NULL)
    return (NULL);
  if ((old = my_last_history(old)) != NULL)
    old->next = new;
  new->id = id++;
  if ((new->att = my_strdup(att)) == NULL)
    return (NULL);
  new->prev = old;
  new->next = NULL;
  return (new);
}
