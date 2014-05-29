/*
** my_append_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_edit
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu May 29 18:51:16 2014 Pierrick Gicquelais
** Last update Thu May 29 18:52:36 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_edit.h"

t_edit		*my_append_char(t_edit *old, char c)
{
  t_edit	*new;

  if ((new = my_new_char()) == NULL)
    return (NULL);
  if ((old = my_last_char(old)) != NULL)
    old->next = new;
  new->c = c;
  new->prev = old;
  new->next = NULL;
  return (new);
}
