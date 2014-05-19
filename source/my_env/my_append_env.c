/*
** my_append_env.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_env
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Mon May 12 10:16:21 2014 Pierrick Gicquelais
** Last update Mon May 19 14:09:37 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_env.h"

t_env		*my_append_env(t_env *old, char *name, char *value)
{
  t_env		*new;

  if ((new = my_new_env()) == NULL)
    return (NULL);
  if ((old = my_last_env(old)) != NULL)
    old->next = new;
  new->name = name;
  new->value = value;
  new->prev = old;
  new->next = NULL;
  return (new);
}
