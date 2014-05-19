/*
** my_append_history.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_history
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 19 13:55:48 2014 Pierrick Gicquelais
** Last update Mon May 19 18:05:43 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_history.h"

char		*my_strldup(char *, char, int);

t_histo		*my_append_history(t_histo *old, int *id, char *att)
{
  t_histo	*new;

  if ((new = my_new_history()) == NULL)
    return (NULL);
  if ((old = my_last_history(old)) != NULL)
    old->next = new;
  new->id = *id;
  if ((new->att = my_strldup(att, '\0', 0)) == NULL)
    return (NULL);
  new->prev = old;
  new->next = NULL;
  (*id)++;
  return (new);
}
