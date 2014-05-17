/*
** my_append_str.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:12:49 2014 Pierrick Gicquelais
** Last update Sat May 17 02:38:54 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

t_str		*my_append_str(t_str *old, char *str)
{
  t_str		*new;

  if ((new = my_new_str()) == NULL)
    return (NULL);
  if ((old = my_last_str(old)) != NULL)
    old->next = new;
  new->str = str;
  new->prev = old;
  new->next = NULL;
  return (new);
}
