/*
** my_append_list.c for 42sh in /home/gicque_p/rendu/PSU_2013_42sh/source/my_exec
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri May 16 14:12:49 2014 Pierrick Gicquelais
** Last update Fri May 16 14:31:54 2014 Pierrick Gicquelais
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_exec.h"

t_list		*my_append_list(t_list *old, char *att)
{
  t_list	*new;

  if ((new = my_new_list()) == NULL)
    return (NULL);
  if ((old = my_last_elem(old)) != NULL)
    old->next = new;
  new->att = my_strdup(att);
  new->prev = old;
  new->next = NULL;
  return (new);
}
