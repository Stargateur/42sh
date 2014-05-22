/*
** my_append_char.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/my_editor
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Tue May 20 17:05:33 2014 Pierrick Gicquelais
** Last update Wed May 21 16:41:46 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_editor.h"

t_edit		*my_append_char(t_edit *old, char c)
{
  t_edit	*new;

  if ((new = my_new_editor()) == NULL)
    return (NULL);
  if ((old = my_last_char(old)) != NULL)
    old->next = new;
    new->c = c;
  new->prev = old;
  new->next = NULL;
  return (new);
}
